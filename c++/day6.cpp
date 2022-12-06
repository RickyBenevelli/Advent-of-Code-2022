#include <iostream>
#include <fstream>

using namespace std; 

void aggiungi_to_marker(char [], char, int);
bool controllo_uguali(char [], int);


int main(int argc, char const *argv[])
{
    fstream in; 
    in.open("../input/day6.txt", ios::in);
    if(!in.is_open()){
        cerr << "Impossibile aprire il file" << endl; 
        exit(1);
    }
    char marker[4] = {};
    char message[14] = {};
    char c; 
    int j = 0, q = 0; 

    while (in.get(c)){

        if(j >= 0){
            j++;
            aggiungi_to_marker(marker, c, 4);
            if(controllo_uguali(marker, 4) == false){
                cout << "MARKER: " << j << endl; 
                j = -1;
            }
        }
        if(q >= 0){
            q++;
            aggiungi_to_marker(message, c, 14);
            if(controllo_uguali(message, 14) == false){
                cout << "MESSAGE: " << q << endl; 
                q = -1;
            }
        
        }
    }
    
    
    return 0;
}

void aggiungi_to_marker(char a[], char c, int dim){
    for (int i = 0; i < dim-1; i++){
        a[i] = a[i+1];
    }
    a[dim-1] = c;    
}

bool controllo_uguali(char a[], int dim){
    for (int i = 0; i < dim; i++){
        if(a[i] == '\0'){
            return true; 
        }
    }
    
    for (int i = 0; i < dim-1; i++){
        for (int k = i+1; k < dim; k++){
            if(a[i] == a[k])
                return true;
        }
    }
    return false;
}