#include <iostream>
#include <string>

using namespace std;

void print_palindrome(int **M,string str,int i,int j)
{

    if (i>j)return;
    if(i==j)
        cout<<str[i];
    if(M[i][j] > M[i+1][j-1] && M[i][j] > M[i+1][j] && M[i][j] > M[i][j-1] && i!=j)
    {
        cout<<str[i];
        print_palindrome(M,str,i+1,j-1);
        cout<<str[i];
    }
    else {
        if(M[i+1][j] >= M[i][j-1])
            print_palindrome(M,str,i+1,j);
        else
            print_palindrome(M,str,i,j-1);


    }
    

}

void print_table(int** M,int size)
{
    cout<<endl;
    for (int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
}

int max(int a,int b)
{
    return a>b?a:b;
}
//the function return the max Palindrom in the string
int palindrom_rec(string str,int i,int j)
{
    if(i>j)return 0;
    if(i==j)return 1;
    if(str[i]==str[j] && i!=j)return (2+ palindrom_rec(str,i+1,j-1));
    else
        return max(palindrom_rec(str,i+1,j),palindrom_rec(str,i,j-1));
}
//using table to help solve the problem.
void palindrom_dyn(string str,int size)
{
    int k=0;
    int **M = (int**)calloc(sizeof(int*),size+1);
    for(int i=0;i<size;i++)
        M[i]=(int*)calloc(sizeof(int),size+1);
    for(int i=0;i<size;i++)
        M[i][i]=1;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1,k=0;j<size;j++,k++)
        {
            if(str[k]==str[j])M[k][j]=(M[k+1][j-1])+2;
            else 
                M[k][j]=max(M[k+1][j],M[k][j-1]);
        }
    }
    cout<<"Table:";
    print_table(M,size);
    cout<<"Max Palindrom: ";
    print_palindrome(M,str,0,size-1);
}


int main()
{
    string str1;
    cout<<"enter string:"<<endl;
    cin>>str1;
    int i=0;
    int j = str1.length()-1;
    cout<<"String: "<<str1<<endl<<"size of String: "<<j+1<<endl;
    cout<<"size of max palindrom: "<<palindrom_rec(str1,i,j)<<endl;
    palindrom_dyn(str1,j+1);
    return 0;
}