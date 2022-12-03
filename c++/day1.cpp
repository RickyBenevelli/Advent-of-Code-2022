#include <iostream>
#include <fstream>


using namespace std; 

int main(int argc, char const *argv[])
{   
    fstream in; 
    in.open("../input/day1.txt", ios::in);
    if (!in.is_open()){
        cerr << "File not existing" << endl;
        exit(1);
    }

    char buffer [32];
    int max1 = 0, totale = 0, max2 = 0, max3 = 0;

    while (in.getline(buffer, 32)){
        if (buffer[0] != '\0'){
            totale += atoi(buffer);

        } else if (buffer[0] == '\0'){
            if (totale > max1){
                max3 = max2;
                max2 = max1; 
                max1 = totale;
            } else if(totale > max2){
                max3 = max2;
                max2 = totale;
            } else if(totale > max3){
                max3 = totale;
            }
            totale = 0; 
        } else {
            cout << "ERRORE " << endl; 
        }
        
    }
    
    cout << "L'elfo porta " << max1 << " calorie" << endl; 
    cout << "La somma dei tre elfi più carichi è: " << (max1 + max2 + max3) << endl; 

    in.close();
    return 0;
}
