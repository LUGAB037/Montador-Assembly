#include <iostream>
#include <fstream>
#include <String>
#include <bitset>
#include <sstream>
using namespace std;

struct Labels {
    string nome;
    int pos = 0;
};

struct Instrucao {
    string nome;
    char formato;
    int opcode;
    int function;
    int rs;
    int rt;
    int rd;
    int sa;
    int coletas = 0;
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

    return reg;
}

string TraduzirBin(string identificado)
{
    if (identificado == "$0" || identificado == "$zero" || identificado == "0")
        return ("00000");
    else if (identificado == "$1" || identificado == "1")
        return ("00001");
    else if (identificado == "$2" || identificado == "2")
        return ("00010");
    else if (identificado == "$3" || identificado == "3")
        return ("00011");
    else if (identificado == "$4" || identificado == "4")
        return ("00100");
    else if (identificado == "$5" || identificado == "5")
        return ("00101");
    else if (identificado == "$6" || identificado == "6")
        return ("00110");
    else if (identificado == "$7" || identificado == "7")
        return ("00111");
    else if (identificado == "$8" || identificado == "8")
        return ("01000");
    else if (identificado == "$9" || identificado == "9")
        return ("01001");
    else if (identificado == "$10" || identificado == "10")
        return ("01010");
    else if (identificado == "$11" || identificado == "11")
        return ("01011");
    else if (identificado == "$12" || identificado == "12")
        return ("01100");
    else if (identificado == "$13" || identificado == "13")
        return ("01101");
    else if (identificado == "$14" || identificado == "14")
        return ("01110");
    else if (identificado == "$15" || identificado == "15")
        return ("01111");
    else if (identificado == "$16" || identificado == "16")
        return ("10000");
    else if (identificado == "$17" || identificado == "17")
        return ("10001");
    else if (identificado == "$18" || identificado == "18")
        return ("10010");
    else if (identificado == "$19" || identificado == "19")
        return ("10011");
    else if (identificado == "$20" || identificado == "20")
        return ("10100");
    else if (identificado == "$21" || identificado == "21")
        return ("10101");
    else if (identificado == "$22" || identificado == "22")
        return ("10110");
    else if (identificado == "$23" || identificado == "23")
        return ("10111");
    else if (identificado == "$24" || identificado == "24")
        return ("11000");
    else if (identificado == "$25" || identificado == "25")
        return ("11001");
    else if (identificado == "$26" || identificado == "26")
        return ("11010");
    else if (identificado == "$27" || identificado == "27")
        return ("11011");
    else if (identificado == "$28" || identificado == "28")
        return ("11100");
    else if (identificado == "$29" || identificado == "29")
        return ("11101");
    else if (identificado == "$30" || identificado == "30")
        return ("11110");
    else if (identificado == "$31" || identificado == "31")
        return ("11111");
}

int main() {
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

    Instrucao instrucoes[] = { // nome, formato, opcode, função, rs, rt, rd, sa, coletas
        {"sll", 'R', 0, 0, 2, 0, 1, 3, 3},
        {"srl", 'R', 0, 2, 0, 0, 1, 3, 3},
        {"jr", 'R', 0, 8, 1, 0, 0, 0, 1},
        {"mfhi", 'R', 0, 16, 0, 0, 1, 0, 1},
        {"mflo", 'R', 0, 18, 0, 0, 1, 0, 1},
        {"mult", 'R', 0, 24, 1, 2, 0, 0, 2},
        {"multu", 'R', 0, 25, 1, 2, 0, 0, 2},
        {"div", 'R', 0, 26, 1, 2, 0, 0, 2},
        {"divu", 'R', 0, 27, 1, 2, 0, 0, 2},
        {"add", 'R', 0, 32, 2, 3, 1, 0, 3},
        {"addu", 'R', 0, 33, 2, 3, 1, 0, 3},
        {"sub", 'R', 0, 34, 2, 3, 1, 0, 3},
        {"subu", 'R', 0, 35, 2, 3, 1, 0, 3},
        {"and", 'R', 0, 36, 2, 3, 1, 0, 3},
        {"or", 'R', 0, 37, 2, 3, 1, 0, 3},
        {"slt", 'R', 0, 42, 2, 3, 1, 0, 3},
        {"sltu", 'R', 0, 43, 2, 3, 1, 0, 3},
        {"mul", 'R', 28, 2, 2, 3, 1, 0, 3},
        {"addi", 'I', 8, 0, 1, 2, 3, 0, 3}

    };

    string* binariolinhas = new string[quant]; //vetor para armazenar os binários da linha;
    for (int i = 0; i < quant; i++)//percorre todas as linhasdo codigo assembly
    {
        int cont = 0; //indicador do caractere da linha
        char carac = lines[i][cont];
        string operacao; // o nome da operação será guardada nele;
        while (carac != ' ') //pega o nome da operação;
        {
            operacao += carac;
            cont++;
            carac = lines[i][cont];

        }

        Instrucao inst;

        for (int i = 0; i < (sizeof(instrucoes) / sizeof(instrucoes[0])); i++)
            if (operacao == instrucoes[i].nome) {
                inst.nome = instrucoes[i].nome;
                inst.formato = instrucoes[i].formato;
                inst.opcode = instrucoes[i].opcode;
                inst.function = instrucoes[i].function;
                inst.rs = instrucoes[i].rs;
                inst.rt = instrucoes[i].rt;
                inst.rd = instrucoes[i].rd;
                inst.sa = instrucoes[i].sa;
                inst.coletas = instrucoes[i].coletas;
            }

        cont++;
        string registrador[4];
        registrador[0] = "0";
        registrador[1] = "";
        carac = lines[i][cont];
        while (carac != ',' && carac != '\0')
        {
            registrador[1] += carac;
            cont++;
            carac = lines[i][cont];

        }

        cont++;
        registrador[2] = "";
        if (inst.coletas > 1) {
            carac = lines[i][cont];
            while (carac != ',' && carac != '\0')
            {
                if (carac != ' ')
                    registrador[2] += carac;

                cont++;
                carac = lines[i][cont];


            }
        }


        cont++;
        registrador[3] = "";
        if (inst.coletas > 2) {
            carac = lines[i][cont];
            while (carac != '\0')
            {
                if (carac != ' ')
                    registrador[3] += carac;

                cont++;
                carac = lines[i][cont];

            }
        }

         for (int i = 0; i < 4; i++)
            registrador[i] = ConverterReg(registrador[i]);

        string rs = registrador[inst.rs];
        string rd = registrador[inst.rd];
        string rt = registrador[inst.rt];
        string sa = registrador[inst.sa];

        string opcode = TraduzirBin(inst.opcode);
        rs = TraduzirBin(rs);
        rd = TraduzirBin(rd);
        rt = TraduzirBin(rt);
        sa = TraduzirBin(sa);

        const int bit6=6;
        const int bit16=16;
        string opcode = bitset<bit6>(inst.opcode).to_string();
        rs = TraduzirBin(rs);
        int possivelimmediate;
        istringstream(rd) >> possivelimmediate;
        cout<<possivelimmediate<<"!";
        rd = TraduzirBin(rd);
        rt = TraduzirBin(rt);
        sa = TraduzirBin(sa);

        if(inst.formato=='R')
        {
            string func = bitset<bit6>(inst.function).to_string();
        binariolinhas[i] = opcode + rs + rt + rd + sa + func;

        }
        else if(inst.formato=='I')
        {

             string func = bitset<bit16>(possivelimmediate).to_string();
             binariolinhas[i] = opcode + rs + rt + func;

        }


    }

    for (int i = 0; i < quant; i++)
    {
        cout << binariolinhas[i] << endl;
    }



}
