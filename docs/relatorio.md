# Relatório de Cobertura de Código com gcovr

## Objetivo
Este relatório documenta o processo de implementação do recurso de cobertura de código usando a ferramenta gcovr em um projeto C. O objetivo é demonstrar como configurar o ambiente, compilar código instrumentado, executar testes e gerar relatórios detalhados de cobertura.

## Configuração do Ambiente

### Pré-requisitos
O projeto foi desenvolvido e executado no seguinte ambiente:

- **Sistema operacional:** Ubuntu 24.04.3 LTS  
- **Plataforma:** WSL 2 (Windows Subsystem for Linux)

### 1 — Instalação das Dependências

#### 1.1 Clonar repositório desse projeto

```https://github.com/BHSA/GCov-with-GCovr```

#### 1.2 Atualizar repositórios e instalar ferramentas básicas

```sudo apt update```
```sudo apt install build-essential -y```

#### 1.3 Verificar as instalações

```gcc --version```
```g++ --version```
```python3 --version```

#### 1.4 Instalar gcovr e dependências

```sudo apt install gcovr```
```sudo apt install python3-pip```
```pip3 install --upgrade gcovr --break-system-packages```

### Passo 2 — Implementação

#### 2.1 Sistema desenvolvido para teste

O sistema testado consiste em um código que simulada a detecção da posição atual de uma alavanca de câmbio de um veículo com transmissão manual. 

Assim, o código de produção apresenta uma função ```cambio``` onde temos:

- ```pos_alavanca```: valor inteiro representando a posição da alavanca

- Retorno de 8 possíveis strings descritivas como "Ponto morto", "Marcha ré", "Marcha 1" a "Marcha 5", ou "Posicao invalida"

A função implementa lógica condicional com if-else e switch-case para mapear valores inteiros para descrições textuais.

#### 2.1 Compilação

De maneira objetiva, para que a suíte de testes seja executada é utilizado o seguinte comando:

```gcc -fprofile-arcs -ftest-coverage -O0 -g cambio.c test_cambio.c -o test_cambio.sh```

E em seguida, o próprio executável de testes gerado:

```./test_cambio.sh```

Sendo as flags:

- ```fprofile-arcs```: Gera dados de fluxo do programa
- ```ftest-coverage```: Instrumenta o código para cobertura
- ```O0```: Desativa otimizações para melhor rastreamento
- ```g```: Inclui informações de debug
- ```o test_cambio.sh```: Nome do executável gerado

A saída esperada consiste na sequência de testes inseridos no arquivo ```test_cambio``` que obedecem o seguinte formato:

Teste ```XX``` - Posicao ```YY```: ```TEXTODESAÍDA```

Até que seja exibida a mensagem:

```=== Fim dos testes ===```

## Utilização do gcovr

Por fim, utilizamos finalmente a ferramenta de Code Coverage ```gcovr``` que pode invocada de comandos com disposições de parâmetros diversas. Dentre elas, selecionamos algumas para fins demonstração.


### Mínima: ```gcovr```

Dessa maneira, teremos a seguinte saída:

```c[
------------------------------------------------------------------------------
                           GCC Code Coverage Report
Directory: .
------------------------------------------------------------------------------
File                                       Lines    Exec  Cover   Missing
------------------------------------------------------------------------------
cambio.c                                      13      13   100%
test_cambio.c                                 14      14   100%
------------------------------------------------------------------------------
TOTAL                                         27      27   100%
------------------------------------------------------------------------------]

### Mínima em arquivo .html: ```gcovr --html -o ./docs/coverage_gcovr_full.html```

Com essa configuração, serão exibidos dados de cobertura em linhas, funções e branches em valor absoluto e percentual.

### Em arquivo .html detalhado: ```gcovr --html-details -o ./docs/coverage_gcovr_full.html```

Com essa configuração, serão exibidos dados de cobertura em linhas, funções e branches em valor absoluto e percentual. Entretando, agora são adicionadas:

- List of Functions, contendo: Call count, Line coverage, Branch coverage, Block coverage.

- Os nomes de arquivos se tornam clicáveis: permitindo verificar a cobertura linha a linha e detalhamentos de quantas vezes cada linha e branch foi executados.

### Formato mais completo em .html: ```gcovr -r . --html-details --branches --decisions --calls   --sort uncovered-number --sort-reverse   --html-single-page js-enabled --html-self-contained --html-block-ids   -o ./docs/coverage_gcovr_full.html -v```

Para fins de exemplo foi utilizado esse comando mais extremo, gerando dos relatórios mais completos pode ser obtido com o código acima em formato .html. Nesse caso, cada um dos parâmetros implementa:

```--html-details``` : inclui código anotado (linhas com hits/faltantes).
```--branches / --txt-metric branch``` : inclui cobertura de branches.
```--decisions``` : inclui decision coverage (quando aplicável).
```--calls``` : mostra coverage de chamadas.
```--sort uncovered-number|uncovered-percent --sort-reverse``` : ordena por pior cobertura.
```--html-single-page js-enabled``` : tudo em um único arquivo interativo.
```--html-self-contained``` : gera um HTML autossuficiente (embute CSS/JS).
```--html-block-ids``` : adiciona IDs de blocos para debugging de branch coverage.
```-r .``` ou ```--root``` : define raiz para caminhos de fonte.
```-i/--include``` : garantir inclusão de arquivos mesmo sem dados.
```--gcov-executable / --object-directory``` : quando gcov/gcda estão em lugares diferentes.
```-v/--verbose``` : ver logs detalhados.

Mais informações a respeito de parâmetros e podem ser verificados através do comando ```gcovr --help``` ou na documentação oficial, disponível em: <http://gcovr.com/>