#include <stdio.h>
#include <cstring>
#include<iostream>
#include <ctime>
#include <cstdlib>
#include<cstdio>
using namespace std;

int VIPsearch(int ID){
    const char *filename1 = "D://data/cash.txt";
    FILE *pFile1;
    pFile1 = fopen(filename1, "r");
    if (NULL == pFile1) {
        printf("Failed to open file!");
        return 1;
    }

    int card=0;
    double balance=0;
    char str[50];
    int VIPlevel=0;

    while (!feof(pFile1)){
        fgets(str, sizeof(str), pFile1);

        sscanf(str, "%d %lf%d", &card, &balance,&VIPlevel);
        if(card==ID) {
            fclose(pFile1);
            return VIPlevel;
        }
    }
    return -1;
};


int main() {

    int card=0;
    int search=0;
    double balance=0;
    double balance_change=0;
    char str[50];
    int VIPlevel=0;
    int VIPlevel_change=0;

    const char *filename1 = "D://data/cash.txt";
    FILE *pFile1;
    pFile1 = fopen(filename1, "r");
    if (NULL == pFile1) {
        printf("Failed to open file!");
        return 1;
    }

    const char *filename2 = "D://data/cash.txt";
    FILE *pFile2;
    pFile2 = fopen(filename2, "r+");
    if (NULL == pFile2) {
        printf("Failed to open file to write!");
        return 1;
    }

    cout<<"input ID"<<endl;
    cin>>search;
//    cout<<"input change"<<endl;
//    cin>>balance_change;
//    cout<<"input VIPlevel"<<endl;
//    cin>>VIPlevel_change;
//    while (!feof(pFile1)){
//        fgets(str, sizeof(str), pFile1);
//
//
//        sscanf(str, "%d %lf%d", &card, &balance,&VIPlevel);
//        if(card!=search)
//        fprintf(pFile2,"%d  \t%lf   \n",card,balance,VIPlevel);
//        else {
//            balance = balance - balance_change;
//            VIPlevel=VIPlevel_change;
//            fprintf(pFile2,"%d  \t%lf   \n",card,balance);
//        }
//    }


int a=VIPsearch(search);
if(a==-1)
    cout<<"VIP ID do not exist"<<endl;
else
cout<<a<<endl;



    fclose(pFile1);
    fclose(pFile2);
    return 0;
}