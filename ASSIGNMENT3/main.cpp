#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Widget{
double itemQuantity;
double costPerWidget;
   Widget* link;
   };

   Widget* fronter;
   Widget* rearer;

int main()
{

   fronter=NULL;
   rearer=NULL;

    Widget* temp;


    ifstream myfile1;
    myfile1.open("DataFile.txt");

    string methodType="";
    int DisCusLeft=0;
    double discountPercent=0;
    double discountInDeci=0;
   while (myfile1) {
         string methodType="";
    double NumbWidgetSold=0;
    double costPerItem=0;
    double WidRecQuantity=0;
    double salePerItem=0;
    double saleAllItem=0;
    double totalSales=0;
    double ifNull=1;
    double totalWidgetSold=0;
     myfile1>> methodType;

    if (methodType=="S"){
    myfile1>> NumbWidgetSold;
      cout << "Sales Info:" << endl;

    temp=fronter;
    if(fronter==NULL) {
        cout << "The stock is empty"<< endl;
        cout << "Remainder of  " << NumbWidgetSold << " Widgets not available. " << endl;
    }



        while((((fronter->itemQuantity)-NumbWidgetSold)<=0)){

                if(fronter->itemQuantity>0){
                salePerItem=(0.30*(fronter->costPerWidget))+(fronter->costPerWidget);

                 saleAllItem=salePerItem*(fronter->itemQuantity);

                totalSales+=saleAllItem;
                totalWidgetSold+=(fronter->itemQuantity);

            cout << fronter->itemQuantity << " at " << salePerItem
            << " each   Sales: $" << saleAllItem << endl;

                }
                else if (fronter->itemQuantity==0){}


             if ( fronter!=rearer){

                 NumbWidgetSold=(NumbWidgetSold-(fronter->itemQuantity));
                 fronter=fronter->link;


              }
             else if (fronter== rearer){




            ifNull=-1* (fronter->itemQuantity-NumbWidgetSold);



                     NumbWidgetSold=-1*(fronter->itemQuantity-NumbWidgetSold);

               cout << "Remainder of  " << NumbWidgetSold << " Widgets not available. " << endl;
           NumbWidgetSold=0;
           cout << ifNull << " Widgets Unavailable" << endl;


          delete fronter;


             }

    }


if ( (((fronter->itemQuantity)-NumbWidgetSold)>0)&& NumbWidgetSold>0){

                salePerItem=(0.30*(fronter->costPerWidget))+(fronter->costPerWidget);

                 saleAllItem=salePerItem*(NumbWidgetSold);
                totalSales+=saleAllItem;
                totalWidgetSold+=NumbWidgetSold;
                fronter->itemQuantity-=NumbWidgetSold;
                 cout << NumbWidgetSold << " at $" << salePerItem
            << " each BHA  Sales: $" << saleAllItem << endl;
             }

cout << " Total Widgets Sold: "<< totalWidgetSold << endl;
cout << "        Total Sales: $ " << totalSales<< endl;
if(DisCusLeft>0){
                totalSales=(1-discountInDeci)*(totalSales);
                cout << "   Discount Applied: " << discountPercent << "%"<< endl;
                cout << "        Total Sales: $ " << totalSales<< endl;

             }

cout << "---------------------------------------------------------" << endl;
DisCusLeft--;

    }

    if(methodType=="R"){
        myfile1>> WidRecQuantity >> costPerItem;

        /** FIFO (Enqueue)-insertion at the end of the linked list*/
        temp= new Widget();
        temp -> itemQuantity=WidRecQuantity;
        temp -> costPerWidget= costPerItem;
        temp -> link =NULL;
        if(fronter==NULL&& rearer==NULL){
            fronter=rearer=temp;
        }
        else{
        rearer-> link =temp;
        rearer=temp;
        }


        cout << "Reciept Info: " << temp->itemQuantity << " at $ " << temp->costPerWidget << " each " << endl;
        cout << "----------------------------------------------------------"<< endl;
    }
    if (methodType=="P"){
        myfile1>> discountPercent;
        DisCusLeft=2;
        discountInDeci=(discountPercent/100);
        cout << "Promotion Discount Info:" << endl;
        cout << "The next 2 customers will be recieving: " << discountPercent << "% discount." << endl;
        cout << "-----------------------------------------------------------"<< endl;

    }

   }

   cout << "------------------------Left in stock--------------------"<< endl;
  Widget* temp2=fronter;
        while(temp2!=NULL){
            cout << "Widgets: " << temp2->itemQuantity << " at $"<< temp2->costPerWidget << "  each" << endl;

        temp2=temp2->link;



        }



    return 0;
}
