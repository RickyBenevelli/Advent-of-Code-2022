#include <iostream>
#include <fstream>

using namespace std; 

#define DIM 52

void pulisci_array(int [], int);
int indice(char c);
bool vuoto(int [], int);

void debugg(int [], int [], int [], int );


int main(int argc, char const *argv[]){

    fstream in; 
    in.open("../input/day3.txt", ios::in);
    if(!in.is_open()){
        cerr << "Error: day3.txt not exist"<< endl;
        exit(1);
    }

    /**********************************************************************/
    /*PARTE 1*/
    /**********************************************************************/
    int priority[52] = {}; // a-z 0-25, A-Z 26-51
    int left_compartments[52] = {};
    int right_compartments[52] = {};
    char buffer[255];

    while (in.getline(buffer, 256)){
        int lenght = strlen(buffer); // controllo quanto è lunga la riga per dividerla a metà
        for (int i = 0; i < lenght/2; i++){ // scorro la prima metà ->
            left_compartments[indice(buffer[i])] += 1;
        }
        for (int i = lenght-1; i >= lenght/2; i--){ // scorro la seconda metà <-
            right_compartments[indice(buffer[i])] += 1;
        }

        // for (int i = 0; i < 52; i++){ // * riga di debug *
        //     if ((left_compartments[i] != 0) && (right_compartments[i] != 0)){
        //         cout << "\033[1;31m" << left_compartments[i] <<"\033[0m" << " ";
        //     } else {
        //         cout << left_compartments[i] << " ";
        //     }
        // }
        // cout << endl;
        // for (int i = 0; i < 52; i++){ // * riga di debug *
        //     if ((left_compartments[i] != 0) && (right_compartments[i] != 0)){
        //         cout << "\033[1;31m" << right_compartments[i] <<"\033[0m" << " ";
        //     } else {
        //         cout << right_compartments[i] << " ";
        //     }
        // }
        // cout << endl;
        
        for (int i = 0; i < 52; i++){ // confronto i due array per trovare se ci sono caratteri uguali
            if ((left_compartments[i] != 0) && (right_compartments[i] != 0)){
                priority[i] += 1; 
            }
        }
        pulisci_array(left_compartments, 52);
        pulisci_array(right_compartments, 52);
    }

    int sum = 0; 
    for (int i = 0; i < 52; i++){
        // cout << priority[i] << " ";
        sum += priority[i]*(i+1);
    }
    cout << endl; 
    // cout << "La somma delle priorità è: " << sum << endl; 
    in.close();

    /**********************************************************************/
    /*PARTE 2*/
    /**********************************************************************/
    fstream in2; 
    in2.open("../input/day3.txt", ios::in);
    if(!in2.is_open()){
        cerr << "Error: day3.txt not exist"<< endl;
        exit(1);
    }
    int first[DIM] = {};
    int second[DIM] = {};
    int third[DIM] = {};
    int priority2[DIM] = {}; // indici: a-z 0-25, A-Z 26-51
    char buffer2[255];

    while (in2.getline(buffer2, 256)){
        int lenght2 = strlen(buffer2);
        if(vuoto(first, DIM)){
            cout << "primo" << endl;
            for (int i = 0; i < lenght2; i++){
                first[indice(buffer2[i])] = 1;
            } 
        }
        else if(vuoto(second, DIM)){
            cout << "secondo" << endl;
            for (int i = 0; i < lenght2; i++){
                second[indice(buffer2[i])] = 1;
            } 
        }
        else if(vuoto(third, DIM)){
            cout << "terzo" << endl;
            for (int i = 0; i < lenght2; i++){
                third[indice(buffer2[i])] = 1;
            }
            debugg(first, second, third, DIM);
            for (int i = 0; i < DIM; i++){
                if((first[i] != 0) && (second[i] != 0) && (third[i] != 0)){
                    priority2[i] += 1; 
                }
            }
            pulisci_array(first, DIM);
            pulisci_array(second, DIM);
            pulisci_array(third, DIM);
        }
        else {
            cout << "ERROR: pieno lo stack" << endl; 
        }
    }
    int sum2 = 0; 
    for (int i = 0; i < DIM; i++){
        // cout << priority[i] << " ";
        sum2 += priority2[i]*(i+1);
    }
    cout << endl; 
    cout << "La somma delle priorità 2 è: " << sum2 << endl; 
    
    in2.close();
    return 0;
}

void pulisci_array(int a[], int d){
    for (int i = 0; i < d; i++){
        a[i] = 0; 
    }
}

int indice(char c){
    if (c >='a' && c <= 'z'){
        return (c -'a');
    } else if (c >= 'A' && c <= 'Z'){
        return (26 + c - 'A');
    }
    return -1;
}

bool vuoto(int a[], int d){
    for (int i = 0; i < d; i++){
        if (a[i] != 0){
            return false;
        }
    }
    return true;
}

void debugg(int a[], int b[], int c[], int dim){
    for (int i = 0; i < dim; i++){ // * riga di debug *
        if ((a[i] != 0) && (b[i] != 0) && (c[i] != 0)){
            cout << "\033[1;31m" << a[i] <<"\033[0m" << " ";
        } else {
            cout << a[i] << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < dim; i++){ // * riga di debug *
        if ((a[i] != 0) && (b[i] != 0) && (c[i] != 0)){
            cout << "\033[1;31m" << b[i] <<"\033[0m" << " ";
        } else {
            cout << b[i] << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < dim; i++){ // * riga di debug *
        if ((a[i] != 0) && (b[i] != 0) && (c[i] != 0)){
            cout << "\033[1;31m" << c[i] <<"\033[0m" << " ";
        } else {
            cout << c[i] << " ";
        }
    }
    cout << endl;
}