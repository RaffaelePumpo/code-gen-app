#include <iostream>
#include "..\codegen\codeGen_ert_rtw\codeGen.h" // Usa il file header generato da MATLAB
using namespace std;
int main() {
/*     codeGen model{};
    model.initialize();  */

    double input_45, input_1;
    cout << "Inserisci In_45: ";
    cin >> input_45;
    cout << "Inserisci In_1: ";
    cin >> input_1;

    codeGen::ExtU_codeGen_T inputs;
    inputs.In_45 = input_45;
    inputs.In_1 = input_1;
    /* model.setExternalInputs(&inputs);  */ 

    //Step
/*     model.faster();
    model.slower();

    const auto& outputs = model.getExternalOutputs();
    cout << "Risultato sum: " << outputs.sum << endl; */

   /*  model.terminate(); */
    return 0;
}
