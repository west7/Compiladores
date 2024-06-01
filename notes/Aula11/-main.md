>[[3_1_o_papel_do_analisador_lexico.pdf|3.1 O papel do analisador léxico]]
# O papel do analisador léxico

O **scanner** ou **analisador léxico** é a primeira fase de um compilador. Ele os caracteres da entrada e produz uma sequência de tokens que serão usados pelo **parser** (analisador sintático). Como o analisador léxico é a única fase que interage diretamente com o programa fonte, ele pode realizar tarefas secundárias como a remoção de comentários e espaços, por exemplo.

[[Interação entre o scanner e o parser.canvas|Interação entre o scanner e o parser]]

## Separação entre análise léxica e gramatical
Há 4 principais motivos para separar a análise léxica da gramatical
	1. A separação pode simplificar uma das duas ou ambas;
	2. A eficiência do compilador é aumentada, visto que, pode-se implementar técnicas como a [[bufferização]] para melhorar a leitura da entrada e extração de tokens;
	3. A separação permite maior portabilidade do compilador;
	4. A separação permite a automação da geração de scanners e parses.

