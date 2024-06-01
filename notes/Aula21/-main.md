Gramática de atributos não possui efeitos colaterais, se tem efeitos colateiras, é apenas uma definição dirigidas pela sintaxe.

Atributos sintetizados X Atributos herdados
Atributos sintetizados dependem, somente, de de atributos de seus filhos, já atributos herdados, dependem  dos atributos de seus irmãos e pais.

Recursão (Não terminal chama ele mesmo a esquerda)
1. A -> Ab | Aa | c
2. A -> Ba | Bb | c
	B -> Aa | Ab | n

Fatoração (token aparece na esquerda várias vezes)
1. A -> aB | aA | ac
	B -> ...
