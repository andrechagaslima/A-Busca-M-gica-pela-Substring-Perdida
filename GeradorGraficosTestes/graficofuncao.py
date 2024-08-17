import numpy as np
import matplotlib.pyplot as plt

# Geração de dados para o gráfico
x = np.linspace(0, 100, 200)  # valores de x de 0 a 10
y = 2 * x  # função exponencial y = 2^x

# Criar o gráfico
plt.figure(figsize=(8, 6))
plt.plot(x, y, label='f(n) = 2n', color='green')
plt.xlabel('n')
plt.ylabel('2n')  # Usando LaTeX para formatar o rótulo do eixo y
plt.title('Gráfico da função linear')
plt.grid(True)
plt.legend()

# Salvar o gráfico como um arquivo PNG
plt.savefig('graficoexponencial.png')

# Mostrar o gráfico
plt.show()
