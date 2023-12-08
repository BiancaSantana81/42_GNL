# Get_Next_Line

Este projeto pede para escrever uma função que retorne uma linha lida de um FD (descritor de arquivo). 

# Sobre o projeto

- Ao chamar a função `get_next_line` em loop, o arquivo de texto apontado pelo descritor de arquivo deve ser lido **uma linha de cada vez**;
- A função deve retornar a linha que foi lida, caso não haja mais nada para ler ou tiver ocorrido um erro, ela deve retornar `null`;
- Ela deve funcionar corretamente tanto ao ler o arquivo como também a partir do `stdin` (entrada de saída padrão);
- O programa deve ser compilado com `-D BUFFER_SIZE=n`, ele definirá o valor do buffer para read() em tempo de compilação.

# Bônus

O bônus deste projeto consiste em  usar apenas uma variável estática e fazer com que a função gerencie vários descritores de arquivo ao mesmo tempo. Como exemplo, ao ler os descritores 3, 4 e 5 a `get_next_line` deve ser capaz de ler um fd diferente por chamada ser perder o thread de leitura de cada descritor de arquivo. 
