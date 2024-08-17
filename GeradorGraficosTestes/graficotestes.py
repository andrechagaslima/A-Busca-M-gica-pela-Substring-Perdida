import numpy as np
import matplotlib.pyplot as plt

n = [1000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]
y = [0.000110, 0.000775,  0.001401, 0.002261, 0.003491, 0.005083, 0.006486, 0.007418, 0.008356, 0.009195, 0.009833]

# Criar o gráfico
plt.figure(figsize=(8, 6))
plt.plot(n, y, color='blue')
plt.xlabel('n')
plt.ylabel('Tempo de execução (segundos)')
plt.title('Programação Dinâmica')
plt.grid(True)

# Salvar o gráfico como um arquivo PNG
plt.savefig('graficopd.png')

# Mostrar o gráfico
plt.show()