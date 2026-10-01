# Calculator-Base C++

## Introdução

Este projeto contém um programa básico de calculadora escrito em C++. Ele permite realizar as quatro operações aritméticas fundamentais: soma (+), subtração (-), multiplicação (*) e divisão (/).

O código é ideal para **iniciantes** que estão a aprender programação, pois demonstra conceitos essenciais de forma clara e direta:
- Entrada e saída de dados (`cin` e `cout`)
- Estruturas de decisão (`if` / `else if` / `else`)
- Tipos de dados (`char` e `float`)
- Tratamento básico de erros (divisão por zero)

Mesmo sendo simples, este código pode servir de base para projetos maiores. Abaixo explicamos detalhadamente como usá-lo, melhorá-lo e integrá-lo em aplicações mais complexas.

---

## Requisitos

Para compilar e executar este código precisas de:

1. Um compilador C++ (recomendado: **g++**)
2. Um terminal / linha de comandos

### Instalação do compilador (iniciantes)

**No Ubuntu / Debian / Linux Mint:**
```bash
sudo apt update
sudo apt install g++
```

**No Fedora / CentOS:**
```bash
sudo dnf install gcc-c++
```

**No Windows:**
- Instala o [MinGW-w64](https://www.mingw-w64.org/) ou o [MSYS2](https://www.msys2.org/)
- Ou usa o Visual Studio Community (mais completo, mas mais pesado)

**No macOS:**
```bash
xcode-select --install
```

---

## Como usar o código (passo a passo para iniciantes)

### 1. Criar o ficheiro

Cria um ficheiro chamado `calculadora.cpp` e cola o código dentro dele.

### 2. Compilar o programa

Abre o terminal na pasta onde está o ficheiro e escreve:

```bash
g++ calculadora.cpp -o calculadora
```

- `g++` → chama o compilador
- `calculadora.cpp` → o ficheiro fonte
- `-o calculadora` → nome do ficheiro executável que será gerado

### 3. Executar o programa

```bash
./calculadora
```

(No Windows: `calculadora.exe`)

### 4. Exemplo de utilização

```
Somar  | + | Subtrair | - | Multiplicar | * | Dividir | / |
Escolha a operacao: +
Numero 1: 15
Numero 2: 7
Soma: 22
```

---

## Explicação linha a linha (focada em iniciantes)

```cpp
#include <iostream>
```
Inclui a biblioteca padrão de entrada e saída. Sem isto não podes usar `cout` nem `cin`.

```cpp
using namespace std;
```
Permite escrever `cout` em vez de `std::cout`. É prático em programas pequenos, mas em projetos maiores costuma-se evitar.

```cpp
int main() {
```
Função principal. Todo o programa começa a executar a partir daqui. O `int` indica que a função devolve um número inteiro (normalmente 0 se correu bem).

```cpp
char op;
float n1, n2;
```
- `char op` → guarda o símbolo da operação (+, -, *, /)
- `float n1, n2` → números com casas decimais (ex: 3.14)

```cpp
cout << "Somar  | + | Subtrair | - | Multiplicar | * | Dividir | / |" << endl;
cout << "Escolha a operacao: ";
cin >> op;
```
Mostra as opções e lê o caracter que o utilizador digitar.

```cpp
cout << "Numero 1: ";
cin >> n1;
cout << "Numero 2: ";
cin >> n2;
```
Pede e lê os dois números.

```cpp
if (op == '+') {
    cout << "Soma: " << (n1 + n2) << endl;
}
else if (op == '-') {
    ...
}
```
Estrutura de decisão. Verifica qual foi a operação escolhida e executa o cálculo correspondente.

```cpp
else if (op == '/') {
    if (n2 != 0) {
        cout << "Divisao: " << (n1 / n2) << endl;
    }
    else {
        cout << "Erro: divisao por zero" << endl;
    }
}
```
Tratamento de erro importante: não se pode dividir por zero.

```cpp
else {
    cout << "Es burro." << endl;
}
```
Mensagem de erro (humorística) caso o utilizador digite um símbolo inválido.

---

## Como melhorar o código (progressão para iniciantes e intermédios)

### Nível 1 – Melhorias básicas (recomendado para iniciantes)

1. **Mensagens mais amigáveis**
   - Em vez de “Es burro.”, usa “Operação inválida. Usa apenas +, -, * ou /.”

2. **Permitir várias operações sem reiniciar o programa**
   ```cpp
   char continuar = 's';
   while (continuar == 's' || continuar == 'S') {
       // ... código da calculadora ...
       cout << "Quer fazer outra operação? (s/n): ";
       cin >> continuar;
   }
   ```

3. **Validar a entrada**
   - Verificar se o utilizador realmente digitou um número.

### Nível 2 – Melhorias intermédias

1. **Usar `switch` em vez de vários `if`**
   ```cpp
   switch (op) {
       case '+':
           cout << "Soma: " << n1 + n2 << endl;
           break;
       case '-':
           // ...
           break;
       // etc.
       default:
           cout << "Operação inválida!" << endl;
   }
   ```

2. **Criar funções separadas**
   ```cpp
   float somar(float a, float b) { return a + b; }
   float subtrair(float a, float b) { return a - b; }
   // ...
   ```

3. **Suportar mais operações**
   - Potência (`pow` da biblioteca `<cmath>`)
   - Raiz quadrada
   - Resto da divisão (`%` – só funciona com inteiros)

### Nível 3 – Para quem já tem mais experiência

1. **Transformar em classe**
   ```cpp
   class Calculadora {
   public:
       float calcular(char op, float a, float b);
   };
   ```

2. **Interface gráfica** (usando bibliotecas como Qt, SFML ou ImGui)

3. **Histórico de operações** (guardar os cálculos feitos)

4. **Suporte a expressões completas** (ex: `3 + 5 * 2`) usando análise sintática (parsing)

5. **Testes unitários** com Google Test ou Catch2

---

## Como integrar em projetos maiores

### 1. Como biblioteca de funções

Extrai as operações para um ficheiro separado:

**operacoes.h**
```cpp
#ifndef OPERACOES_H
#define OPERACOES_H

float somar(float a, float b);
float subtrair(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);

#endif
```

**operacoes.cpp**
```cpp
#include "operacoes.h"
#include <stdexcept>

float somar(float a, float b) { return a + b; }
float subtrair(float a, float b) { return a - b; }
float multiplicar(float a, float b) { return a * b; }

float dividir(float a, float b) {
    if (b == 0) throw std::runtime_error("Divisão por zero!");
    return a / b;
}
```

Depois no teu programa principal:
```cpp
#include "operacoes.h"
```

### 2. Em aplicações console mais complexas

Podes usar esta lógica dentro de um menu principal:

```
1. Calculadora
2. Conversor de unidades
3. Sair
```

### 3. Em jogos ou simulações

As operações matemáticas são a base de quase tudo: física, pontuações, economia de jogos, etc.

### 4. Em ferramentas de linha de comandos (CLI)

Podes transformar o programa para receber argumentos:
```bash
./calculadora 15 + 7
```

---

## Dicas de boas práticas (para todos os níveis)

| Prática                    | Porquê é importante                          | Nível recomendado |
|---------------------------|----------------------------------------------|-------------------|
| Nomes claros de variáveis | Facilita a leitura                           | Iniciante         |
| Comentários úteis         | Explica o “porquê”, não o “o quê”            | Iniciante         |
| Tratamento de erros       | Evita crashes                                | Iniciante         |
| Funções pequenas          | Código mais fácil de testar e reutilizar     | Intermédio        |
| Evitar `using namespace std` | Previne conflitos de nomes                   | Intermédio        |
| Separar lógica da interface | Facilita mudanças futuras                    | Avançado          |
| Testes automatizados      | Garante que mudanças não quebram nada        | Avançado          |

---

## Possíveis problemas e soluções (para iniciantes)

| Problema                              | Causa mais comum                     | Solução                                      |
|---------------------------------------|--------------------------------------|----------------------------------------------|
| “command not found: g++”              | Compilador não instalado             | Instala o g++ (ver secção Requisitos)        |
| O programa fecha imediatamente        | Estás a executar no Windows com duplo clique | Corre a partir do terminal                   |
| Números com vírgula não funcionam     | O programa espera ponto (.)          | Usa ponto em vez de vírgula (3.14)           |
| “Divisão por zero”                    | Segundo número é 0                   | O programa já trata isto                     |
| Mensagem “Es burro.”                  | Digitaste um símbolo errado          | Usa apenas +, -, * ou /                      |

---

## Próximos passos sugeridos (caminho de aprendizagem)

1. **Agora** → Compila e corre o código várias vezes. Experimenta erros de propósito.
2. **Depois** → Adiciona o ciclo `while` para fazer várias operações.
3. **A seguir** → Transforma as operações em funções.
4. **Mais tarde** → Cria um menu com várias ferramentas (calculadora + conversor de temperaturas, etc.).
5. **Avançado** → Aprende a usar `std::vector` para guardar o histórico de cálculos.

---

## Conclusão

Este código simples é um excelente ponto de partida. Não subestimes o valor de dominar bem as bases. Muitos programadores experientes ainda usam estruturas semelhantes em ferramentas internas ou scripts rápidos.

O segredo não é escrever o código mais complexo possível desde o início. O segredo é:

1. Fazer funcionar
2. Tornar legível
3. Tornar reutilizável
4. Tornar robusto

Boa sorte nos teus estudos de programação!

---

**Autor do README:** Gerado para fins educativos  
**Linguagem:** C++  
**Nível:** Iniciante → Intermédio
```
