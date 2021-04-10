#include <iostream>
#include <iomanip>
#include <ctime>

void printBenchmarkTable(){
    std::cout << "Data Size"    << std::setw(15) << "Insertion"  << std::setw(15) << "Selection"  << std::setw(15) << "Bubble" << std::setw(15) 
              << "Heap"         << std::setw(15) << "Quick"      << std::setw(15) << "Merge" << std::endl;
}

void insertion(){
   
};

double insertionTime(int size){
    double start, finish;
    start = clock();
    insertion();
    finish = clock();
    return (double)((finish - start) / (double)CLOCKS_PER_SEC);
}
void printBenchmarks(int* size, int i){
    std::cout << size[i]    << std::setw(15) << insertionTime(size[i])  << std::setw(15) << "SelectionV"  << std::setw(15) << "BubbleV" << std::setw(15) 
              << "HeapV"         << std::setw(15) << "QuickV"      << std::setw(15) << "MergeV" <<std::endl;
}


int main() {
    int size[] = {100000, 200000, 300000, 400000, 500000};
    int len = sizeof(size)/sizeof(size[0]);

    int randomVal;
    srand(time(0));


    printBenchmarkTable();
    for(int i=0; i<len; i++){
        printBenchmarks(size, i);
    }

    
}