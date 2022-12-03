#include <iostream>
#include <fstream>


using namespace std; 


int main(int argc, char const *argv[])
{   
    fstream in; 
    in.open("../input/day2.txt", ios::in);
    if (!in.is_open()){
        cerr << "File not existing" << endl;
        exit(1);
    }

    char buffer [32];
    int punteggio = 0, punteggio2 = 0;

    while (in.getline(buffer, 32)){
        switch (buffer[0])
        {
        case 'A': // sasso
            switch (buffer[2])
            {
            case 'X':
                punteggio += 4;
                punteggio2 += 0+3; 
                break;
            case 'Y': 
                punteggio += 8;
                punteggio2 += 3+1;
                break;
            case 'Z':
                punteggio += 3;
                punteggio2 += 6+2;
                break;
            default:
                break;
            }
            break;
        case 'B': //carta
            switch (buffer[2])
            {
            case 'X':
                punteggio += 1;
                punteggio2 += 0+1;
                break;
            case 'Y':
                punteggio += 5;
                punteggio2 += 3+2;
                break;
            case 'Z':
                punteggio += 9;
                punteggio2 += 6+3;
                break;
            default:
                break;
            }
            break;
        case 'C': //forbici
            switch (buffer[2])
            {
            case 'X': //sasso
                punteggio += 7;
                punteggio2 += 0+2;
                break;
            case 'Y': //carta
                punteggio += 2;
                punteggio2 += 3+3;
                break;
            case 'Z': //forbice
                punteggio += 6;
                punteggio2 += 6+1;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    
    cout << "Il risultato è: " << punteggio << endl; 
    cout << "Il risultato 2 è: " << punteggio2 << endl; 
    

    in.close();
    return 0;
}


