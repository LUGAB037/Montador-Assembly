#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Labels {
    string nome;
    int pos = 0;
};

// retorna 1 caso a linha seja o início de um label (palavra seguida de ':')
bool detectarLabels(string l) {
    //bool toReturn = new bool;
    bool toReturn = 0;
    bool k = 0; // vai definir se há ou não uma palavra antes dos dois pontos

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

string ConverterReg(string reg) {
    cout << reg << endl;

    if (reg == "$zero")
        reg = "$0";
    else if (reg == "$at")
        reg = "$1";
    else if (reg[1] == 'v') {
        if (reg == "$v0")
            reg = "$2";
        else if (reg == "$v1")
            reg = "$3";
    }
    else if (reg[1] == 'a') {
        if (reg == "$a0")
            reg = "$4";
        else if (reg == "$a1")
            reg = "$5";
        else if (reg == "$a2")
            reg = "$6";
        else if (reg == "$a3")
            reg = "$7";
    }
    else if (reg[1] == 't') {
        if (reg == "$t0")
            reg = "$8";
        else if (reg == "$t1")
            reg = "$9";
        else if (reg == "$t2")
            reg = "$10";
        else if (reg == "$t3")
            reg = "$11";
        else if (reg == "$t4")
            reg = "$12";
        else if (reg == "$t5")
            reg = "$13";
        else if (reg == "$t6")
            reg = "$14";
        else if (reg == "$t7")
            reg = "$15";
        else if (reg == "$t8")
            reg = "$24";
        else if (reg == "$t9")
            reg = "$25";
    }
    else if (reg[1] == 's') {
        if (reg == "$s0")
            reg = "$16";
        else if (reg == "$s1")
            reg = "$17";
        else if (reg == "$s2")
            reg = "$18";
        else if (reg == "$s3")
            reg = "$19";
        else if (reg == "$s4")
            reg = "$20";
        else if (reg == "$s5")
            reg = "$21";
        else if (reg == "$s6")
            reg = "$22";
        else if (reg == "$s7")
            reg = "$23";
        else if (reg == "$sp")
            reg = "$29";
    }
    else if (reg[1] == 'k') {
        if (reg == "$k0")
            reg = "$26";
        else if (reg == "$k1")
            reg = "$27";
    }
    else if (reg == "$gp")
        reg = "$28";
    else if (reg == "$fp")
        reg = "$30";
    else if (reg == "$ra")
        reg = "$31";



    cout << reg;

    system("pause");

    return reg;
}

 string TraduzirBin(string identificado)
{
    if (identificado == "$0" || identificado == "$zero")
        return ("00000");
    else if (identificado == "$1")
        return ("00001");
    else if (identificado == "$2")
        return ("00010");
    else if (identificado == "$3")
        return ("00011");
    else if (identificado == "$4")
        return ("00100");
    else if (identificado == "$5")
        return ("00101");
    else if (identificado == "$6")
        return ("00110");
    else if (identificado == "$7")
        return ("00111");
    else if (identificado == "$8")
        return ("01000");
    else if (identificado == "$9")
        return ("01001");
    else if (identificado == "$10")
        return ("01010");
    else if (identificado == "$11")
        return ("01011");
    else if (identificado == "$12")
        return ("01100");
    else if (identificado == "$13")
        return ("01101");
    else if (identificado == "$14")
        return ("01110");
    else if (identificado == "$15")
        return ("00111");
    else if (identificado == "$16")
        return ("10000");
    else if (identificado == "$17")
        return ("10001");
    else if (identificado == "$18")
        return ("10010");
    else if (identificado == "$19")
        return ("10011");
    else if (identificado == "$20")
        return ("10100");
    else if (identificado == "$21")
        return ("10101");
    else if (identificado == "$22")
        return ("10110");
    else if (identificado == "$23")
        return ("10111");
    else if (identificado == "$24")
        return ("11000");
    else if (identificado == "$25")
        return ("11001");
    else if (identificado == "$26")
        return ("11010");
    else if (identificado == "$27")
        return ("11011");
    else if (identificado == "$28")
        return ("11100");
    else if (identificado == "$29")
        return ("11101");
    else if (identificado == "$30")
        return ("11110");
    else if (identificado == "$31")
        return ("11111");
}
 string TraduzirBin(int opOUfunc)
 {
     if (opOUfunc == 0)
         return ("000000");
     else if (opOUfunc == 1)
         return ("000001");
     else if (opOUfunc == 2)
         return ("000010");
     else if (opOUfunc == 3)
         return ("000011");
     else if (opOUfunc == 4)
         return ("000100");
     else if (opOUfunc == 5)
         return ("000101");
     else if (opOUfunc == 6)
         return ("000110");
     else if (opOUfunc == 7)
         return ("000111");
     else if (opOUfunc == 8)
         return ("001000");
     else if (opOUfunc == 9)
         return ("001001");
     else if (opOUfunc == 10)
         return ("001010");
     else if (opOUfunc == 11)
         return ("001011");
     else if (opOUfunc == 12)
         return ("001100");
     else if (opOUfunc == 13)
         return ("001101");
     else if (opOUfunc == 14)
         return ("001110");
     else if (opOUfunc == 15)
         return ("000111");
     else if (opOUfunc == 16)
         return ("010000");
     else if (opOUfunc == 17)
         return ("010001");
     else if (opOUfunc == 18)
         return ("010010");
     else if (opOUfunc == 19)
         return ("010011");
     else if (opOUfunc == 20)
         return ("010100");
     else if (opOUfunc == 21)
         return ("010101");
     else if (opOUfunc == 22)
         return ("010110");
     else if (opOUfunc == 23)
         return ("010111");
     else if (opOUfunc == 24)
         return ("011000");
     else if (opOUfunc == 25)
         return ("011001");
     else if (opOUfunc == 26)
         return ("011010");
     else if (opOUfunc == 27)
         return ("011011");
     else if (opOUfunc == 28)
         return ("011100");
     else if (opOUfunc == 29)
         return ("011101");
     else if (opOUfunc == 30)
         return ("011110");
     else if (opOUfunc == 31)
         return ("011111");
     else if (opOUfunc == 32)
         return ("100000");
     else if (opOUfunc == 33)
         return ("100001");
     else if (opOUfunc == 34)
         return ("100010");
     else if (opOUfunc == 35)
         return ("100011");
     else if (opOUfunc == 36)
         return ("100100");
     else if (opOUfunc == 37)
         return ("100101");
     else if (opOUfunc == 38)
         return ("100110");
     else if (opOUfunc == 39)
         return ("100111");
     else if (opOUfunc == 40)
         return ("101000");
     else if (opOUfunc == 41)
         return ("101001");
     else if (opOUfunc == 42)
         return ("101010");
     else if (opOUfunc == 43)
         return ("101011");


 }

int main () {
    ifstream fin; // cria objeto para a saída
    fin.open("Arquivo.txt"); // "linka" o arquivo ao objeto
if (!fin.is_open())
{
    cout << "A abertura do arquivo falhou!" << endl;
    exit(EXIT_FAILURE);
}

    string line; // "line" será usada para armazenar provisoariamente cada linha do código
    int quant = 0; // "quant" será usado para contar a quantidade de linhas do programa
    int quantLabels = 0; // usado para aarmazenar quantidade total labels

    // obtem a quantidade total de linhas do programa e a quantidade total de labels
    while (fin.good()) {
        getline(fin, line);
        quant++;

        if (detectarLabels(line) == 1)
            quantLabels++;

    }
    fin.close();

    string* lines = new string[quant]; // cria lista de strings para armazenar as linhas do código assembly
    Labels* posLabels = new Labels[quantLabels]; // cria lista que vai armazenar posição de cada label

    quant = 0;
    quantLabels = 0;
    fin.open("Arquivo.txt");
if (!fin.is_open())
{
    cout << "A abertura do arquivo falhou!" << endl;
    exit(EXIT_FAILURE);
}

    // armazena cada linha do código assembly na lista "lines"
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

        // remove caracteres do início de cada linha
        while (lines[quant][0] == ':' or lines[quant][0] == '\t' or lines[quant][0] == ' ')
            lines[quant] = lines[quant].substr(1);

        quant += 1;
    }
    fin.close();

    string * binariolinhas = new string [quant]; //vetor para armazenar os binários da linha;
    for (int i = 0; i < quant; i++)//percorre todas as linhasdo codigo assembly
    {
        int cont=0; //indicador do caractere da linha
        char carac = lines[i][cont];
        string operacao; // o nome da operação será guardada nele;
        while (carac != ' ') //pega o nome da operação;
        {
             operacao += carac;
             cont++;
             carac = lines[i][cont];

        }

        if (operacao == "add")
        {
            cont++;
            string reg1;
             carac = lines[i][cont];
            while (carac != ',')
            {
                reg1 += carac;
                cont++;
                carac = lines[i][cont];

            }
            reg1 = ConverterReg(reg1); // converte os registradores tipo $s4 para $20, por exemplo

            cont++;
            string reg2;
            carac = lines[i][cont];
            while (carac != ',')
            {
                if (carac != ' ')
                    reg2 += carac;

                    cont++;
                    carac = lines[i][cont];
            }
            reg2 = ConverterReg(reg2); // converte os registradores tipo $s4 para $20, por exemplo

            cont++;
            string reg3;
             carac = lines[i][cont];
            while (carac != '\0')
            {
                if (carac != ' ')
                reg3 += carac;

                cont++;
                carac = lines[i][cont];

            }
            reg3 = ConverterReg(reg3); // converte os registradores tipo $s4 para $20, por exemplo

            string opcode = TraduzirBin(0);
            string rd = TraduzirBin(reg1);
            string rs = TraduzirBin(reg2);
            string rt = TraduzirBin(reg3);
            string shamt = TraduzirBin("$0");
            string func = TraduzirBin(32);
            binariolinhas[i] = opcode + rs + rt + rd + shamt + func;

        }
    }

    for (int i = 0; i < quant; i++)
    {
        cout << binariolinhas[i] << endl;
    }



}


