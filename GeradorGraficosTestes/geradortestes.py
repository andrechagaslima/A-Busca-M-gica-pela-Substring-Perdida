def gerar_texto_e_salvar(filename, n):
    import random
    import string

    # Definir o alfabeto brasileiro, incluindo "ç"
    alfabeto = string.ascii_letters + 'çÇ'

    # Gerar um texto aleatório de 10000 caracteres usando apenas letras do alfabeto brasileiro
    texto = ''.join(random.choices(alfabeto, k=1000000))

    # Gerar um padrão aleatório de até 10 caracteres usando o mesmo alfabeto
    tamanho_padrao = random.randint(1, 10)
    padrao = ''.join(random.choices(alfabeto, k=tamanho_padrao))

    # Gerar n requisições com valores entre 0-3000 e 3001-9999
    requisicoes = [(random.randint(0, 300000), random.randint(500000, 999999)) for _ in range(n)]

    # Abrir arquivo para escrita
    with open(filename, 'w') as file:
        # Escrever o texto na primeira linha
        file.write(f"{texto}\n")
        
        # Escrever o padrão na segunda linha
        file.write(f"{padrao}\n")
        
        # Escrever a quantidade de requisições na terceira linha
        file.write(f"{n}\n")
        
        # Escrever as requisições nas linhas subsequentes
        for req in requisicoes:
            file.write(f"{req[0]} {req[1]}\n")

    print(f"Texto e valores gerados e salvos em '{filename}'.")

# Exemplo de uso
n = 10  # Quantidade de requisições a gerar
nome_arquivo = "saida5.txt"
gerar_texto_e_salvar(nome_arquivo, n)