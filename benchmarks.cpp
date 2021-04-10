#include <iostream>
#include <iomanip>
#include <ctime>


void insertionSort(int size){
   
}

void selectionSort(int size){
   
}

void bubbleSort(int size){

}

void heapSort(int size){

}

double insertionTime(int size){
    double start, finish;
    start = clock();
    insertionSort(size);
    finish = clock();
    return (double)((finish - start) / (double)CLOCKS_PER_SEC);
}

double selectionTime(int size){
    double start, finish;
    start = clock();
    insertionSort(size);
    finish = clock();
    return (double)((finish - start) / (double)CLOCKS_PER_SEC);
}

double bubbleTime(int size){
    double start, finish;
    start = clock();
    bubbleSort(size);
    finish = clock();
    return (double)((finish - start) / (double)CLOCKS_PER_SEC);
}

double heapTime(int size){
    double start, finish;
    start = clock();
    heapSort(size);
    finish = clock();
    return (double)((finish - start) / (double)CLOCKS_PER_SEC);
}

void printBenchmarkTable(){
    std::cout << "Data Size"    << std::setw(15) << "Insertion"  << std::setw(15) << "Selection"  << std::setw(15) << "Bubble" << std::setw(15) 
              << "Heap"         << std::setw(15) << "Quick"      << std::setw(15) << "Merge" << std::endl;
}

void printBenchmarks(int* size, int i){
    int input = size[i];
    std::cout << input      << std::setw(15) << insertionTime(input)  << std::setw(15) << selectionTime(input)  << std::setw(15) << bubbleTime(input) << std::setw(15) 
              << heapTime(input)    << std::setw(15) << "QuickV"      << std::setw(15) << "MergeV" <<std::endl;
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