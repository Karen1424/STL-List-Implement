#include "List.h"

 int main(){
     List<int> my;
     my.push_back(30);
     my.push_back(20);
     my.push_back(9);
     my.push_back(20);
     my.push_front(10);
     my.push_back(5);
     my.push_front(1);
     my.pop_front();
     my.pop_back();
     my.insert(2,17);
     my.erase(2);
     std::cout << my.getSize() << std::endl;
     for(int i = 0; i < my.getSize();++i){
     std::cout << my[i]<< " ";
     }


     return 0;
 }
