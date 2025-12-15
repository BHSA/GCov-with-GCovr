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

#### 1.2 Atualizar repositórios e instalar ferramentas básicas

```gcc --version```
```g++ --version```
```python3 --version```