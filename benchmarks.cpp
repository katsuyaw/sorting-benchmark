#include <iostream>
#include <iomanip>

void printBenchmarkTable(){
    std::cout << "Data Size"    << std::setw(15) << "Insertion"  << std::setw(15) << "Selection"  << std::setw(15) << "Bubble" << std::setw(15) 
              << "Heap"         << std::setw(15) << "Quick"      << std::setw(15) << "Merge";
}

void printBenchmarks(int i){
    
};

int main() {
    int size[] = {100000, 200000, 300000, 400000, 500000};
    int len = sizeof(size)/sizeof(size[0]);

    int randomVal;
    srand(time(0));

    

    printBenchmarkTable();
    for(int i=0; i<len; i++){
        std::cout << "\n" << size[i];
        printBenchmarks(i);
    }

    
}