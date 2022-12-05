#include <iostream>
#include <fstream>



using namespace std;


int main(int argc, char const *argv[])
{
    fstream in; 
    in.open("../input/input.txt", ios::in);
    if(!in.is_open()){
        cerr << "Impossibile aprire il file" << endl; 
        exit(1);
    }
    
    char c; 
    int indice_stack = 1, parentesi = 0, spazi = 0, acapi = 0;
    int lettura_mappa = 0; 
    

    while (in.get(c)){

        if(lettura_mappa == 0){    
            if(c == ' '){
                if (spazi == 4){
                    indice_stack += 1;
                    spazi = 0;
                }
                spazi += 1;
                acapi = 0;
                continue;
            }
            else if(c == '['){
                if(acapi != 1){
                    indice_stack += 1;
                }
                acapi = 0;
                spazi = 0;
                parentesi += 1;
                continue;
            }
            else if(c == ']'){
                parentesi -= 1;
                continue;
            }
            else if (c == '\n'){
                acapi += 1;
                indice_stack = 1;
                spazi = 0;
            }
            else { // c allora è una lettera

                if(parentesi == 1){
                    cout << c << " "; 
                } 
                else {
                    lettura_mappa = 1;
                }
            }
        }
    }
    

    in.close();
    return 0;
}