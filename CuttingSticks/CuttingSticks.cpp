//
//  main.cpp
//  CuttingSticks
//
//  Created by Miguel Cuellar on 3/3/16.
//  Copyright © 2016 Miguel Cuellar. All rights reserved.
//

#include <iostream>
#import "stdlib.h"
using namespace std;


int matDatos[50][50];
int palo[50];

void llenar(int ix,int iy){
    int aux;
    matDatos[ix][iy]=100000;
    for (int i=ix; i<iy-1; i++) {
        aux=palo[iy+1]-palo[ix]+matDatos[ix][i]+matDatos[i+1][iy];
        if (matDatos[ix][iy]>aux) {
            matDatos[ix][iy]=aux;
        }
    }
}

int main() {
    
    int n,tam=1, j;
    cin>>tam;
    while (tam!=0){
        cin>>n;
        palo[0]=0;
        
        for (int j=1; j<=n; j++) {
            cin>>palo[j];
        }
        palo[n+1]=tam;
        for (int i=1; i<=n; i++) {
            for (int ix=0; ix<n; ix++) {
                matDatos[ix][ix]=0;
            }
            for (int ix=0; ix<n;ix++) {
                int iy=ix+1;                    //SEGUNDA DIAGONAL
                matDatos[ix][iy]=palo[iy+1]-palo[ix];
            }
        }
        
        for (int ix=2; ix<=n; ix++) {
            for (int iy=0; iy<n; iy++) {
                j=iy+ix;
                llenar(iy,j);
            }
        }
     /*   for (int ix=0; ix<=n; ix++) {
            for (int iy=0; iy<=n; iy++) {     //IMPRIMIR
                cout<<matDatos[ix][iy]<<"         ";
            }
            cout<<endl;
        }
        for (int p=0; p<=n+1; p++) {
            cout<<palo[p]<<" ";
        }
     */
        cout<<"The minimum cutting is "<<matDatos[0][n]<<"."<<endl;
        cin>>tam;
    }
    
    //5239,222,341,28,24,274,1700
    return 0;
}
