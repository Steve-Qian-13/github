#include<iostream>
#include<vector>
#include<string>
using namespace std;
 
 
int pmt[1000];
   void get_pmt(const string& p) 
   {
      pmt[0] = 0; // 第一个字符的最长相同前缀后缀为0
      for(int i = 1, j = 0; i<p.length(); i++) 
      {
         while(j && p[i] != p[j])  j = pmt[j-1]; //如果不相同，移动p，这里如果j=0并且两个字符还不相同，也就默认pmt[i] = 0了
          if( p[i] == p[j])  //如果相同，则得到该位置pmt[i]的值，继续向后比较
          {
            j++;
            pmt[i] = j;
          }     
      }
   }
   int kmp(const string &s,const string &p)
   {     
        for(int i = 0, j = 0; i < s.length(); i++)
        {
         while(j && s[i] != p[j])  j = pmt[j-1]; 
         if(s[i] == p[j])
         {
            j++;   // 两者相等，继续匹配
         }
         if(j==p.length())
         {
            return i-j+1;//匹配成功，返回下标
                                                
         }
        }
        return -1;// 未匹配成功，返回-1
   }
 
int main()
{    
  
        string s;
        string p;
        getline(cin,s); //读入s
        getline(cin,p);  //读入 p
        get_pmt(p); //获取 pmt数组
        cout<<kmp(s,p)<<endl;
 
          return 0;
 
 
  }