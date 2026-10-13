# PUC-Minas - Ciência da Computação
## AED1 - Algoritmos e Estruturas de Dados I
### Estudo Dirigido 10 (ED10) - Grupos de dados heterogêneos (`struct`)

- **Autor:** Guilherme Caçuci Ladislau
- **Matrícula:** 851609
- **Data:** 13/10/2026
- **Tema:** Introdução à programação V - Grupos de dados heterogêneos (Arranjos e Matrizes baseados em estruturas)

---

## 🎯 Objetivo do Projeto

Este estudo dirigido tem como objetivo introduzir a criação e manipulação de **grupos de dados heterogêneos** (`struct`) na linguagem C para representar estruturas de dados mais seguras e organizadas, como **arranjos unidimensionais (vetores)** e **arranjos bidimensionais (matrizes)**.

Ao longo das atividades, busca-se desenvolver o domínio sobre:
* **Encapsulamento básico:** Agrupar dados (ponteiro de elementos, dimensões e indexadores) em uma única estrutura (`int_Array` e `int_Matrix`).
* **Alocação Dinâmica de Memória:** Uso consciente de `malloc` e `free` através de funções construtoras (`new_int_Array` / `new_int_Matrix`) e destrutoras (`free_int_Array` / `free_int_Matrix`), evitando vazamentos de memória (*memory leaks*).
* **Manipulação de Ponteiros e Referências:** Uso de tipos por referência (`ref_int_Array` e `ref_int_Matrix`) e acesso a campos via operador seta (`->`).
* **Persistência em Arquivos:** Leitura e gravação estruturada de vetores e matrizes em arquivos de texto (`.TXT`).
* **Lógica Estruturada:** Implementação de algoritmos de busca, comparação, ordenação e álgebra linear (transposta, soma escalar, produto matricial e matriz identidade) respeitando boas práticas de programação sem o uso de interrupções abruptas (`break`).

---

## 💻 Tecnologias e Ferramentas Utilizadas

* **Linguagem:** C (Padrão C99/C11)
* **Compilador:** GCC (GNU Compiler Collection)
* **Sistema Operacional:** Linux (Ubuntu)
* **Bibliotecas Padrão:** `stdio.h`, `stdlib.h`, `stdbool.h`, `string.h`, `time.h`, `math.h` (integradas via `io.h`)
* **Biblioteca Auxiliar:** `io.h` (Biblioteca didática de entrada/saída e gerenciamento de memória fornecida na disciplina de AED1 - PUC-Minas)

---

## 📁 Estrutura de Arquivos

* **`io.h`**: Biblioteca padrão da disciplina com definições auxiliares de entrada, saída e alocação.
* **`Exemplo1000.c`** (ou `Exemplo1001.c` a `Exemplo1010.c`): Programa com os 10 métodos de exemplo (`Method_01` a `Method_10`) abordando alocação dinâmica, leitura, gravação e cópia de arranjos (`int_Array`) e matrizes (`int_Matrix`) usando `struct` e ponteiros.
* **`Exemplo1011.c` a `Exemplo1020.c` / `Exemplo10E1.c` e `Exemplo10E2.c`** (ou integrados em um único arquivo `Exemplo1011.c` / `Ed10.c`): Resolução de todos os exercícios propostos (`1011` a `1020`) e das tarefas extras (`10E1` e `10E2`).

---

## ⚙️ Como Compilar e Executar (Linux / GCC)

Abra o terminal na pasta do projeto e utilize os comandos abaixo (adicione a flag `-lm` caso sua versão da `io.h` utilize funções de `math.h`):

### 1. Para o Arquivo de Exemplos (`Exemplo1000.c`)
```bash
gcc -o Exemplo1000 Exemplo1000.c -lm
./Exemplo1000
```

### 2. Para o Arquivo Integrado de Exercícios (`Exemplo1011.c` ou `Ed10.c`)
*(Caso todos os exercícios estejam reunidos em um único menu)*
```bash
gcc -o Exemplo1011 Exemplo1011.c -lm
./Exemplo1011
```

### 3. Para Compilar os Exercícios Individualmente (Caso salvos separados)
```bash
# Exercício 01 (1011) - Gerar números aleatórios em intervalo
gcc -o Exemplo1011 Exemplo1011.c -lm && ./Exemplo1011

# Exercício 02 (1012) - Procurar valor em arranjo
gcc -o Exemplo1012 Exemplo1012.c -lm && ./Exemplo1012

# Exercício 03 (1013) - Comparar dois arranjos
gcc -o Exemplo1013 Exemplo1013.c -lm && ./Exemplo1013

# Exercício 04 (1014) - Somar dois arranjos com constante
gcc -o Exemplo1014 Exemplo1014.c -lm && ./Exemplo1014

# Exercício 05 (1015) - Verificar se arranjo é decrescente
gcc -o Exemplo1015 Exemplo1015.c -lm && ./Exemplo1015

# Exercício 06 (1016) - Obter matriz transposta
gcc -o Exemplo1016 Exemplo1016.c -lm && ./Exemplo1016

# Exercício 07 (1017) - Testar se matriz só contém zeros
gcc -o Exemplo1017 Exemplo1017.c -lm && ./Exemplo1017

# Exercício 08 (1018) - Comparar igualdade de duas matrizes
gcc -o Exemplo1018 Exemplo1018.c -lm && ./Exemplo1018

# Exercício 09 (1019) - Somar duas matrizes com constante
gcc -o Exemplo1019 Exemplo1019.c -lm && ./Exemplo1019

# Exercício 10 (1020) - Produto de duas matrizes
gcc -o Exemplo1020 Exemplo1020.c -lm && ./Exemplo1020

# Tarefa Extra 1 (10E1) - Ordenar arranjo em ordem decrescente
gcc -o Exemplo10E1 Exemplo10E1.c -lm && ./Exemplo10E1

# Tarefa Extra 2 (10E2) - Testar se produto matricial é igual à Identidade
gcc -o Exemplo10E2 Exemplo10E2.c -lm && ./Exemplo10E2
```

> **💡 Dica para Testes Rápidos:** Ao executar o programa integrado (`./Exemplo1011`), digite a **opção `99`** no menu antes de testar os exercícios. Ela gera automaticamente os arquivos de entrada (`DADOS.TXT`, `DADOS1.TXT`, `DADOS2.TXT`, `MATRIZ1.TXT` e `MATRIZ2.TXT`) com valores padrão prontos para uso.

---

## 📋 Descrição das Atividades

### Parte 1: Exemplos (`Exemplo1000.c`)
| Opção | Método | Descrição |
| :---: | :--- | :--- |
| **1** | `method_01` | Exibe um arranjo alocado de 5 posições estruturado com `int_Array`. |
| **2** | `method_02` | Lê um arranjo de inteiros do teclado e exibe seus elementos na tela. |
| **3** | `method_03` | Lê um arranjo do teclado e grava os dados no arquivo `ARRAY1.TXT`. |
| **4** | `method_04` | Lê os elementos do arquivo `ARRAY1.TXT` e mostra na tela. |
| **5** | `method_05` | Lê `ARRAY1.TXT`, cria uma cópia dinâmica com `ref_int_Array` e exibe ambos. |
| **6** | `method_06` | Cria e exibe uma matriz 3x3 estruturada com `ref_int_Matrix`. |
| **7** | `method_07` | Lê as dimensões e elementos de uma matriz pelo teclado e a exibe. |
| **8** | `method_08` | Lê uma matriz do teclado e grava no arquivo `MATRIX1.TXT`. |
| **9** | `method_09` | Lê uma matriz a partir do arquivo `MATRIX1.TXT` e exibe na tela. |
| **10** | `method_10` | Lê `MATRIX1.TXT`, cria uma cópia em outra estrutura de matriz e exibe ambas. |

---

### Parte 2: Exercícios e Extras (`Exemplo1011.c`)
| Opção | Exercício | Função Principal | Descrição |
| :---: | :---: | :--- | :--- |
| **11** | **1011** | `RandomIntGenerate` | Gera N valores inteiros aleatórios dentro de um intervalo [a, b] e grava em `DADOS.TXT`. |
| **12** | **1012** | `arraySearch` | Procura um determinado valor inteiro dentro do arranjo lido de `DADOS.TXT`. |
| **13** | **1013** | `arrayCompare` | Compara se dois arranjos (`DADOS1.TXT` e `DADOS2.TXT`) possuem tamanhos compatíveis e elementos iguais. |
| **14** | **1014** | `arrayAdd` | Calcula a soma de dois arranjos, multiplicando o segundo por uma constante k (A1 + k * A2). |
| **15** | **1015** | `isArrayDecrescent` | Verifica se o arranjo lido de `DADOS1.TXT` está ordenado de forma decrescente (sem uso de `break`). |
| **16** | **1016** | `matrixTranspose` | Obtém e exibe a matriz transposta a partir da matriz lida de `MATRIZ1.TXT`. |
| **17** | **1017** | `matrixZero` | Testa se uma matriz (`MATRIZ1.TXT`) contém exclusivamente valores iguais a zero. |
| **18** | **1018** | `matrixCompare` | Verifica a igualdade entre duas matrizes (`MATRIZ1.TXT` e `MATRIZ2.TXT`). |
| **19** | **1019** | `matrixAdd` | Calcula a soma de duas matrizes, com a segunda escalada por uma constante (M1 + k * M2). |
| **20** | **1020** | `matrixProduct` | Calcula o produto matricial (M1 * M2) verificando a compatibilidade de dimensões. |
| **21** | **10E1** | `sortArrayDown` | Ordena um arranjo (`DADOS1.TXT`) em ordem decrescente pelo método de trocas de posição. |
| **22** | **10E2** | `identityMatrix` | Verifica se o produto de duas matrizes (M1 * M2) resulta em uma matriz identidade (I). |
| **99** | **[AUX]** | `criarArquivosDeTeste` | Gera automaticamente os arquivos `.TXT` de teste no diretório atual. |

---

## 🛠️ Boas Práticas e Restrições Atendidas

1. **Alocação e Reciclagem de Memória:** Todo espaço alocado dinamicamente via `new_int_Array` e `new_int_Matrix` (`malloc`) é devidamente liberado ao final de cada método com `free_int_Array` e `free_int_Matrix` (`free`).
2. **Controle de Laços:** As buscas e verificações não utilizam `break` ou `continue`; a interrupção de laços que não precisam percorrer todos os dados é feita exclusivamente por expressões lógicas na condição do `while`.
3. **Tratamento de Erros:** Validação de ponteiros nulos (`NULL`), abertura de arquivos e compatibilidade de dimensões utilizando blocos `if/else` com mensagens descritivas.
