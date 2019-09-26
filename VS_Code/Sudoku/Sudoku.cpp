#include <iostream>
using namespace std;

int main(){
    //Datos
    int iSud[9][9],iSumF=0,iSumC=0,iSumMat=0,marcador;
    bool bFila=true;
    bool bCol=true;
    bool bMat=true;

    //Ingresar datos
    for (int i=0;i<9;i++){
        for (int k=0;k<9;k++){
            cin>>iSud[i][k];
        }
    }
    //Validar filas
    for (int i=0;i<9;i++){
        for (int k=0;k<9;k++){
            iSumF+=iSud[i][k];
        }
        if (iSumF != 45){
            bFila=false;

        }
        iSumF=0;
    }

    //Validar columnas
      for (int i=0;i<9;i++){
        for (int k=0;k<9;k++){
            iSumC+=iSud[k][i];
        }
        if (iSumC != 45){
            bCol=false;

        }
        iSumC=0;
    }

    //Validate 3x3
    for (int r=0;r<9&&bMat==true;r++){
        iSumMat=0;
        if ( r==0 || r==3 || r==6){
            marcador=0;
            for (int i=marcador;i<marcador+3;i++){
                for (int k=marcador;k<marcador+3;k++){
                    iSumMat+=iSud[i][k];
                    }
             }
              if (iSumMat != 45){
                bMat=false;
            }
              marcador+=3;
        }
    }

    //Desplegar resultados
    if (bFila && bCol && bMat)
    {
        cout<<"YES"<<endl;
    }
    if (bFila == false || bCol == false || bMat == false)
    {
        cout<<"NO"<<endl;
    }

    

    return 0;
}