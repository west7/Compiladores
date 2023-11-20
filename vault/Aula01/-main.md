
>[1_Introdução](1_introducao.pdf)
# [O que são compiladores?](1_introducao.pdf)
Um compilador é um programa que pega outro programa escrito em uma linguagem alvo e traduz para uma linguagem fonte.

Normalmente, a entrada de um compilador é um programa escrito em linguagem tradicional, e a saída pode ser tanto outro programa em linguagem tradicional como em linguagem de máquina [[assembly]].

[Fluxo Programa Executável](Fluxo%20Programa%20Executável.canvas)
# [Análise e Síntese](Análise%20e%20Síntese.md)
Um compilador pode ser dividido em duas partes análise e síntese. As duas partes podem ser pensadas como uma escalada de montanha, onde, a subida seria a parte de análise, o nível de abstração aumenta gradativamente, até um ponto no qual a análise constrói uma representação intermediária do código original, e, na descida da montanha, a síntese irá construir o programa alvo a partir desta representação.  As duas partes de um compilador podem também ser desmembradas em 3 fases cada.
# [Fases de um compilador](Fases%20de%20um%20compilador.md)
As fases de um compilador são 6: **Análise léxica, Análise Sintática, Análise Semântica, Geração de código intermediário, Otimizador de Código, Gerador de código.** Sendo as 3 primeiras pertencentes à análise e as 3 últimas pertencentes à síntese.
# [Interfaces de Vanguarda e Retaguarda](Interfaces%20de%20Vanguarda%20e%20Retaguarda.md)
Na prática,  as fases podem ser divididas também em interfaces: vanguarda e retaguarda. A interface de vanguarda contém as fases que são dependentes do programa fonte. E a interface de retaguarda inclui as fases que são focadas em gerar o programa alvo, ou seja, que dependem da máquina alvo. Em um cenário ideal as duas interfaces são independentes, ou seja, é possível fixar uma delas e trocar somente a outra, o que permite a criação de diferentes compiladores com diferentes objetivos.

