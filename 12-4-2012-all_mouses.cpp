#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    list<int> all_mouses;

    for (int i=1; i<=n; i++){
        all_mouses.push_back(i);
    }

    list<int>::iterator ptr = all_mouses.begin();
    while (all_mouses.size() > 1){
        // erase the first element
        all_mouses.erase(all_mouses.begin());
        ptr = all_mouses.begin();
        bool flag = true;

        // check before delete other elements
        if (all_mouses.size() == 1){
            break;
        }
        // delete elements until the end of the list
        while (ptr != all_mouses.end()){
            for (int i=0; i<=k; i++){
                if (flag){
                    flag = false;
                    continue;
                }
                ptr++;
                if (ptr == all_mouses.end()){
                    break;
                }
                else if (i==k){
                    all_mouses.erase(ptr--);
                }
            }
        } 
    }

    printf("\n%d\n", all_mouses.front());

    return 0;
}
