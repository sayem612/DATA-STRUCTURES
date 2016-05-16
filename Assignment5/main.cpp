#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int originalArr[50];//this is the original arr, used as a global variable
int comparison[3]={0,0,0};//each index in this array is for each Sorting Algorithm's # of comparison
int interchange[3]={0,0,0};// each index in this array is for each Sorting Algorithm's # of interchange
/**Calling a subroutine to read a group of numbers to be sorted*/
int ReadGroup(string filename){


    ifstream myfile1;
    myfile1.open(filename.c_str());
    if(myfile1.is_open()){
    int increment=0;
    string heading;
    int arraysize;
    myfile1>> arraysize;
    getline(myfile1, heading);
     cout << arraysize << " " << heading  << endl;
    // int originalArr[10];
    myfile1>> originalArr[increment];
    while(myfile1){
        cout << originalArr[increment]<< " " ;
        increment++;
         myfile1>> originalArr[increment];

    }
    cout << endl;
    myfile1.close();
     return arraysize;

    }
    else {
        cout << "File does not exist!"<< endl;
        return -1;

    }

}

/**Function that prints the elements in the array*/
void Print(int arr[], int sizearr){
 for (int i=0; i<sizearr;i++){
    cout << arr[i]<< " ";
  }
cout << endl;
}

/**Bubble Sort Algorithm*/
void  bubble_sort (int arr[], int sizearr){
    //int comparison=0;
   // int interchange=0;
  for (int i = 0; i < sizearr; i++){

    for (int j = 0; j < sizearr-i-1; j++){
      comparison[0]++;//index in the array allocated to record bubble sort comparisons
      if (arr[j] > arr[j+1])
     {

        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        interchange[0]++;//index in the array allocated to record bubble sort interchanges
      }
    }
  }
  }



  /**QuickSort Algorithm*/
  void quick_sort(int arr[], int left, int right){
      int i=left, j=right;
      int temp;// temporary variable
      int pivot=arr[(left+right)/2];// position of the middle element

      //partition section in this algorithm

      while (i<=j){    //same as while(left<j || i<right)
        while(arr[i]<pivot){
            comparison[1]++;
            i++;
        }
        while(arr[j]>pivot){
            comparison[1]++;
            j--;
        }
        if(i<=j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
            interchange[1]++;
        }
      };

      //recursion section in this algorithm
      if(left<j){
        quick_sort(arr,left, j);
      }
      if(i<right){
        quick_sort(arr,i,right);
      }

  }




  /**HeapSort Algorithm*/

void checkRootNode(int arr[], int root, int arrsize) {
  int left = 2*root;
  int right = 2*root + 1;
  if (left < arrsize && arr[root] < arr[left]) {
      std::swap(arr[root], arr[left]);
      checkRootNode(arr, left, arrsize);
  }
  if (right < arrsize && arr[root] < arr[right]) {
      std::swap(arr[root], arr[right]);
      checkRootNode(arr, right, arrsize);
  }
}


void buildHeap(int arr[], int arrsize) {
  for (int i=arrsize/2; i>0; --i) {
      checkRootNode(arr, i, arrsize);
  }
}


void heap_sort(int arr[], int arrsize) {
  while (arrsize > 1) {
      std::swap(arr[1], arr[arrsize-1]);
      checkRootNode(arr, 1, --arrsize);
  }
}

 /**
  void max_heapify(int a[], int i, int n)
{
    int l,r,largest,loc;
    l=2*i;
    r=(2*i+1);
    if((l<=n)&&a[l]>a[i])
       largest=l;
    else
       largest=i;
    if((r<=n)&&(a[r]>a[largest]))
       largest=r;
    if(largest!=i)
    {
         loc=a[i];
         a[i]=a[largest];
         a[largest]=loc;
         max_heapify(a, largest,n);
    }
}
void build_max_heap(int a[], int n)
{
    for(int k = n/2; k >= 1; k--)
    {
        max_heapify(a, k, n);
    }
}
void heap_sort(int arr[], int sizearr)
{

    build_max_heap(arr,sizearr);
    int i, temp;//declaring the required increment and temporary variable
    for (i = sizearr; i >= 2; i--)
    {
        temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        max_heapify(arr, 1, i - 1);
    }
}
*/

  /**Calling a subprogram to sort the values using the three sorts*/
  void three_sorts(int bubblearr[], int quickarr[], int heaparr[],
                   int sizearr, int left, int right){
  //cout << "This is the Bubble Sort:" << endl;
  bubble_sort(bubblearr,sizearr);
  //cout << "This is the Quick Sort:" << endl;
  quick_sort(quickarr, left, right);
 // cout << "This is the Heap Sort:" << endl;
  heap_sort(heaparr,sizearr);
  }


  /**Calling a subprogram that compares these three sorts*/
  void compare(){
  string sortnames[3]={"Bubble Sort", "Quick Sort", "Heap Sort"};

  int mostcomp=0, middlecomp=0, leastcomp=comparison[0];// variable to compare the numbers of comparisons
  string mostcname, middlecname, leastcname;//variable to store the sort names based on increasing # of comparisons

  int mostchange=0, middlechange=0, leastchange=0;//variable to compare the numbers of interchanges
  string mostiname, middleiname, leastiname;//variable to store the sort names based on increasing # of interchanges

  //this is for Comparison
  for (int i=0; i<3; i++){
    if(comparison[i]>mostcomp){
        mostcomp=comparison[i];
        mostcname=sortnames[i];
    }
    if (comparison[i]<leastcomp){
        leastcomp=comparison[i];
        leastcname=sortnames[i];
    }
    if(((mostcomp!=comparison[i])&&(leastcomp!=comparison[i])))
    {
        middlecomp=comparison[i];
        middlecname=sortnames[i];
    }
  }
  cout << "Most comparison sort: " << mostcname << " with " << mostcomp << "comparison." << endl;
  cout << "Middle comparison sort: "<< middlecname << " with " << middlecomp << "comparison." << endl;
  cout << "Least comparison sort: "<< leastcname << " with " <<  leastcomp << "comparison" << endl;


  //this is for Interchanges
  for (int i=0; i<3; i++){
    if(interchange[i]>mostchange){
        mostchange=interchange[i];
        mostiname=sortnames[i];
    }
    if (interchange[i]<leastchange){
        leastchange=interchange[i];
        leastiname=sortnames[i];
    }
    if(((mostchange!=interchange[i])&&(leastchange!=interchange[i])))
    {
        middlechange=interchange[i];
        middleiname=sortnames[i];
    }
  }
  cout << "Most interchanging sort: " << mostiname << " with " << mostchange << "comparison." << endl;
  cout << "Middle interchanging sort: "<< middleiname << " with " << middlechange << "comparison." << endl;
  cout << "Least interchanging sort: "<< leastiname << " with " <<  leastchange << "comparison" << endl;
  }
int main()
{
/**
   int arr[]={800,43,2,4,53};
   bubble_sort(arr,5);
   int z=sizeof(arr)/sizeof(arr[0]);
   cout << z << "is the greatest" << endl;
   */
    int p;

    p= ReadGroup("Group1.txt");//storing the array input size, while storing arraysize in variable p

   int bubbleArr[p];
   int quickArr[p];
   int heapArr[p];
   for (int i=0; i<p; i++){
    //cout << *(p+i)<<" " ;
    bubbleArr[i]=quickArr[i]=heapArr[i]=originalArr[i];
   // cout << originalArr[i] << " ";
   }
   cout << endl;
   // ReadGroup("Group2.txt");

     int left=0;//position of the left most index in the array
   int right=p-1;//position of the right most index in the array

    three_sorts(bubbleArr,quickArr, heapArr, p, left, right );


   // bubble_sort(bubbleArr, p);
    Print(bubbleArr,p);
    cout << "Bubble Sort Neeeded: " << comparison[0] << " comparison and "
    << interchange[0] << " interchange." << endl;







   //quick_sort(quickArr,left, right);
   Print(bubbleArr,p);
    cout << "Quick Sort Neeeded: " << comparison[1] << " comparison and "
    << interchange[1] << " interchange." << endl;




   // heap_sort(heapArr,p);
    Print(heapArr,p);//p+15 shows a picture of whats going on
    cout << "Heap Sort Neeeded: " << comparison[2] << " comparison and "
    << interchange[2] << " interchange." << endl;

   /**cout << "This is bubble array after sort" << endl;
   for (int i=0; i<p; i++){
    //cout << *(p+i)<<" " ;
    cout << bubbleArr[i] << " ";
   }
   cout << endl;
   */

    cout << "Hello world!" << endl;
    return 0;
}
