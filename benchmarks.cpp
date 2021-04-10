#include <iostream>
#include <iomanip>
#include <ctime>


template<class T>
void insertionSort(T* array, int size)
{   
    int target, location;
    T key;

    for(target=0; target<size; target++){
        // condition: next element of target is smaller than target
        if(array[target]>array[target+1]){
            // record the location of the next element
            location = target + 1;
            // store the element to key
            key = array[location];

            // keep moving each element to the right by 1
            do{
                array[location] = array[location-1];
                location--;
            }// until the element moving is smaller than key
            while(location>0 && array[location-1]>key);
            // locate key to the position
            array[location] = key;
        }
    }
}

void selectionSort(int size){
   
}

void bubbleSort(int size){

}

void heapSort(int size){

}

void quickSort(int size){

}

template<class T>
void mergeSort(T* array, int start, int mid, int end){

}

template<class T>
double sortTime(T* array, int size, char sortType){
    clock_t start, finish;
    switch(sortType){
        case 'i':{
            start = clock();
            insertionSort(array, size);
            finish = clock();
            break;
        }
        case 's':{
            start = clock();
            selectionSort(array, size);
            finish = clock();
            break;
        }
        case 'b':{
            start = clock();
            bubbleSort(array, size);
            finish = clock();
            break;
        }
        case 'h':{
            start = clock();
            heapSort(array, size);
            finish = clock();
            break;
        }
        case 'q':{
            start = clock();
            quickSort(array, size);
            finish = clock();
            break;
        }
        case 'm':{
            start = clock();
            mergeSort(array, size);
            finish = clock();
            break;
        }

    }
    
    return (double)((finish - start) / (double)CLOCKS_PER_SEC);
}

// template<class T>
// double iTime(T* array, int size){
//     double start, finish;
//     start = clock();
//     insertionSort(array, size);
//     finish = clock();
//     return (double)((finish - start) / (double)CLOCKS_PER_SEC);
// }

// template<class T>
// double sTime(T* array, int size){
//     double start, finish;
//     start = clock();
//     insertionSort(array, size);
//     finish = clock();
//     return (double)((finish - start) / (double)CLOCKS_PER_SEC);
// }

// template<class T>
// double bTime(T* array, int size){
//     double start, finish;
//     start = clock();
//     bubbleSort(size);
//     finish = clock();
//     return (double)((finish - start) / (double)CLOCKS_PER_SEC);
// }

// template<class T>
// double hTime(T* array, int size){
//     double start, finish;
//     start = clock();
//     heapSort(size);
//     finish = clock();
//     return (double)((finish - start) / (double)CLOCKS_PER_SEC);
// }

// template<class T>
// double qTime(T* array, int size){
//     double start, finish;
//     start = clock();
//     quickSort(0);
//     finish = clock();
//     return (double)((finish - start) / (double)CLOCKS_PER_SEC);
// }


// double mTime(int* array, int size){
//     double start, finish;
//     start = clock();
//     mergeSort(array,0,0,0);
//     finish = clock();
//     return (double)((finish - start) / (double)CLOCKS_PER_SEC);
// }

void printBenchmarkTable(){
    std::cout << "Data Size"    << std::setw(15) << "Insertion"  << std::setw(15) << "Selection"  << std::setw(15) << "Bubble" << std::setw(15) 
              << "Heap"         << std::setw(15) << "Quick"      << std::setw(15) << "Merge" << std::endl;
}


// global array pointers
int* iArray, *sArray, *bArray, *hArray, *qArray, *mArray;

int main() {
    int arraySize[] = {10000, 20000, 30000, 40000, 50000};
    int len = sizeof(arraySize)/sizeof(arraySize[0]);
    srand(time(0));

    printBenchmarkTable();
    for(int i=0; i<len; i++){          
        // dynamically allocate new memory
        int size = arraySize[i];
        iArray = new int[size];
        sArray = new int[size];
        bArray = new int[size];
        hArray = new int[size];
        qArray = new int[size];
        mArray = new int[size];

        // randomize each array
        for(int j=0; j<arraySize[i]; j++){  
            int randomVal = rand() % 100;
            iArray[j] = randomVal;
            sArray[j] = randomVal;
            bArray[j] = randomVal;
            hArray[j] = randomVal;
            qArray[j] = randomVal;
            mArray[j] = randomVal;
        }
        
        // benchmarking
        // std::cout<< size
        //          << std::setw(15) << iTime(iArray, size) << std::setw(15) << sTime(sArray, size) << std::setw(15) << bTime(bArray, size) << std::setw(15) << hTime(hArray, size)
        //          << std::setw(15) << qTime(qArray, size) << std::setw(15) << mTime(mArray, size) << std::endl;

        std::cout<< size
                 << std::setw(15) << sortTime(iArray, size, 'i') << std::setw(15) << sortTime(iArray, size, 's') << std::setw(15) << sortTime(iArray, size, 'b') 
                 << std::setw(15) << sortTime(iArray, size, 'h') << std::setw(15) << sortTime(iArray, size, 'q') << std::setw(15) << sortTime(iArray, size, 'm') << std::endl;

        // free memory
        delete iArray;  iArray = nullptr;
        delete sArray;  sArray = nullptr;
        delete bArray;  bArray = nullptr;
        delete hArray;  hArray = nullptr;
        delete qArray;  qArray = nullptr;
        delete mArray;  mArray = nullptr;
    
    }    
}