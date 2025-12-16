# GCov with GCovr

Projeto de demonstração de cobertura de código para C usando `gcov`/`gcovr`.

O `gcov` é a ferramenta de cobertura do GCC que instrumenta a compilação e coleta dados de execução (arquivos `.gcno`/`.gcda`), permitindo analisar quais linhas e branches foram executados durante a execução dos testes. 

Em contrapartida o `gcovr` é uma ferramenta em Python que agrega e reporta dados de cobertura gerados pelo GCC (`gcov`) em formatos legíveis (texto, HTML e XML). Ela facilita gerar relatórios consolidados de linhas, funções e branches, e é frequentemente usada em CI para monitorar regressões de cobertura.

## Visão geral
Este repositório contém um exemplo mínimo (função `cambio`) e uma suíte de testes (`test_cambio.c`) para demonstrar como gerar relatórios de cobertura com `gcovr`.

## Estrutura de arquivos (Antes da execução)

```
GCOV-WITH-GCOVR/
├── README.md                             # Documentação principal do projeto
├── cambio.c                              # Código fonte do sistema sob teste (SUT)
├── test_cambio.c                         # Executável dos testes compilado
└── docs/
    └── relatorio.md                      # Documento de referência do repositório
```
**Acesso ao relatório:** [docs/relatorio.md](docs/relatorio.md) — abra este arquivo para visualizar o relatório detalhado do projeto.

Devido a natureza educativa do código, não foram implementados recursos como makefile ou docker, apesar de serem completamente válidos em uma aplicação real de teste.