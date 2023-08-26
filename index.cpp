#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Labels {
    string nome;
    int pos = 0;
};

// retorna 1 caso a linha seja o in�cio de um label (palavra seguida de ':')
bool detectarLabels(string l) {
    //bool toReturn = new bool;
    bool toReturn = 0;
    bool k = 0; // vai definir se h� ou n�o uma palavra antes dos dois pontos

    for (int i = 0; i < l.size(); i++)
    {
        if (l[i] != '\t')
            if (l[i] != ':')
                k = 1;
            else
                if (k == 1)
                    toReturn = k;
    }
    return toReturn;
}

int main () {
    ifstream fin; // cria objeto para a sa�da
    fin.open("Arquivo.txt"); // "linka" o arquivo ao objeto

    string line; // "line" ser� usada para armazenar provisoariamente cada linha do c�digo
    int quant = 0; // "quant" ser� usado para contar a quantidade de linhas do programa
    int quantLabels = 0; // usado para aarmazenar quantidade total labels

    // obtem a quantidade total de linhas do programa e a quantidade total de labels
    while (fin.good()) {
        getline(fin, line);
        quant++;

        if (detectarLabels(line) == 1)
            quantLabels++;

    }
    fin.close();

    string* lines = new string[quant]; // cria lista de strings para armazenar as linhas do c�digo assembly
    Labels* posLabels = new Labels[quantLabels]; // cria lista que vai armazenar posi��o de cada label

    quant = 0;
    quantLabels = 0;
    fin.open("Arquivo.txt");

    // armazena cada linha do c�digo assembly na lista "lines"
    while (fin.good()) {
        getline(fin, lines[quant]);

        if (detectarLabels(lines[quant]) == 1) {
            posLabels[quantLabels].pos = quant;

            string nomeLabel;
            while (lines[quant][0] != ':') {
                nomeLabel += lines[quant][0];
                lines[quant] = lines[quant].substr(1);

                posLabels[quantLabels].nome = nomeLabel;
            }


            quantLabels++;

        }

        // remove caracteres do in�cio de cada linha
        while (lines[quant][0] == ':' or lines[quant][0] == '\t' or lines[quant][0] == ' ')
            lines[quant] = lines[quant].substr(1);

        quant += 1;
    }
    fin.close();




}
