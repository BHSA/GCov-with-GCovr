# Relatório de Cobertura de Código com gcovr

## Objetivo
Este relatório documenta o processo de implementação do recurso de cobertura de código usando a ferramenta gcovr em um projeto C. O objetivo é demonstrar como configurar o ambiente, compilar código instrumentado, executar testes e gerar relatórios detalhados de cobertura.

## Configuração do Ambiente

### Pré-requisitos
O projeto foi desenvolvido e executado no seguinte ambiente:

- **Sistema operacional:** Ubuntu 24.04.3 LTS  
- **Plataforma:** WSL 2 (Windows Subsystem for Linux)

### Passo 1 — Instalação das Dependências

#### 1.1 Atualizar repositórios e instalar ferramentas básicas

```sudo apt update```
```sudo apt install build-essential -y```

#### 1.2 Verificar as instalações

```gcc --version```
```g++ --version```
```python3 --version```

#### 1.3 Instalar gcovr e dependências

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

