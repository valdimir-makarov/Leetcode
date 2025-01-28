 #include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
bool  isSpecial(string s){
char c = s[0];
     for(auto &x:s){
         if(c!=x){
            return false;
         }
     }
return true;
 }

int  longestSpecialSubstring(string s){
 int maxValue = INT_MIN;
  for(int i =0;i<s.size();i++){
     for(int j = i+1;j<s.size()-1;j++){
      
 string subString = s.substr(i,j-i);
  if(isSpecial(subString)){
  int length = subString.length();
   
   if(length>=3){
     maxValue=max(maxValue,length);


   }


  }

     }
  }
   return maxValue;


}


int main(){
string string = "bubunbuubuuuuubububububu";
 int result  = longestSpecialSubstring(string);
 cout<<result<<endl;
    return 0;
}