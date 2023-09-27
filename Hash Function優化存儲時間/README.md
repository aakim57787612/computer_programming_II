hash function (int, string) 的設計  
int 的 hash function 的 key 為此 int %總 int 數量    
string 的 hash function 的 key 為此 string 第一個字的 ASCII CODE%總 string 數量  
  
容器有總 int/string 數量個入口，每個入口第一個 data 皆為 linked list 的 first，  
key 一樣的 insert 各自的 linked list  
