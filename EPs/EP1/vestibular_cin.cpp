#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Implementando mergesort utilizando os 
// atributos de um struct para realizar a ordenação com base em mais de um critério

struct Inscritos {
    string nome;
    string curso;
    int nota;
    int idade;
    int ordem_inscricao;

    Inscritos() : nome(""), curso(""), nota(0), idade(0), ordem_inscricao(0) {}
    Inscritos(string n, string c, int nt, int i, int ordem) {
        nome = n; curso = c; nota = nt; idade = i; ordem_inscricao = ordem;
    }
};

// Método que faz a comparação e desempate
bool comparar(const Inscritos& a, const Inscritos& b) {
    if (a.nota != b.nota) { return a.nota > b.nota; }
    if (a.idade != b.idade) { return a.idade > b.idade; }
    return a.ordem_inscricao < b.ordem_inscricao;
}

// O mergesort é um algoritmo de ordenação estável, 
// logo o primeiro aluno que aparecer mesmo que aconteça um empate 
// de todos os critérios saberemos quem foi o primeiro aluno a se inscrever
void merge(vector<Inscritos>& vect, int l, int r) {
    int m = (l + r) / 2;
    vector<Inscritos> temp(vect.size());
    for (int i = l; i <= r; ++i) {
        temp[i] = vect[i];
    }
    int i1 = l;
    int i2 = m + 1;
    for(int curr = l; curr <= r; curr++) {
        if(i1 == m+1) { vect[curr] = temp[i2++]; }
        else if(i2 > r) { vect[curr] = temp[i1++]; }
        else if (comparar(temp[i1], temp[i2])) {
            vect[curr] = temp[i1++];
        } else {
            vect[curr] = temp[i2++];
        }
    }
}

void mergesort(vector<Inscritos>& vect, int l, int r) {
    if (l < r) {
        int m = (l + r)/2;
        mergesort(vect, l, m);
        mergesort(vect, m + 1, r);
        merge(vect, l, r);
    }
}

int menor_nota(const vector<Inscritos>& vect, string curso) {
    int comp = (curso == "IA") ? 50 : 100;
    if (vect.size() > comp) {
        return vect[comp - 1].nota;
    } else if (!vect.empty()) {
        return vect.back().nota;
    } else {
        return 0;
    }
}

void print_func(const vector<Inscritos>& vect, int nota_de_corte = 0, string curso = "") {
    int comp1 = (curso == "IA") ? 25 : 50;
    int comp2 = (curso == "IA") ? 50 : 100;

    if (vect.empty()) {
        cout << "?)\n";
        cout << "- 1a entrada\n";
        cout << "- 2a entrada\n";
        return;
    }

    cout << nota_de_corte << ")\n";
    cout << "- 1a entrada\n";
    int k = 0;
    int total = vect.size();

    if (total <= comp1) {
        for (k; k < total; ++k)
            cout << vect[k].nome << "\n";
        cout << "- 2a entrada\n";
    } else if (total <= comp2) {
        for (k; k < comp1; ++k)
            cout << vect[k].nome << "\n";
        cout << "- 2a entrada\n";
        for (k; k < total; ++k)
            cout << vect[k].nome << "\n";
    } else {
        for (k; k < comp1; ++k)
            cout << vect[k].nome << "\n";
        cout << "- 2a entrada\n";
        for (k; k < comp2; ++k)
            cout << vect[k].nome << "\n";
    }
}

int main() {
    int n_inscritos;
    cin >> n_inscritos;

    vector<Inscritos> alunos_cc, alunos_ec, alunos_ia;

    for (int i = 0; i < n_inscritos; i++) {
        string nome, curso;
        int nota, idade;
        cin >> nome >> curso >> nota >> idade;
        Inscritos aluno(nome, curso, nota, idade, i);
        if (curso == "CC") alunos_cc.push_back(aluno);
        else if (curso == "EC") alunos_ec.push_back(aluno);
        else if (curso == "IA") alunos_ia.push_back(aluno);
    }
    mergesort(alunos_cc, 0, alunos_cc.size() - 1);
    mergesort(alunos_ec, 0, alunos_ec.size() - 1);
    mergesort(alunos_ia, 0, alunos_ia.size() - 1);

    cout << ">> CC (nota de corte = ";
    if (!alunos_cc.empty()) print_func(alunos_cc, menor_nota(alunos_cc, "CC"), "CC");
    else print_func(alunos_cc);

    cout << ">> EC (nota de corte = ";
    if (!alunos_ec.empty()) print_func(alunos_ec, menor_nota(alunos_ec, "EC"), "EC");
    else print_func(alunos_ec);

    cout << ">> IA (nota de corte = ";
    if (!alunos_ia.empty()) print_func(alunos_ia, menor_nota(alunos_ia, "IA"), "IA");
    else print_func(alunos_ia);

    return 0;
}