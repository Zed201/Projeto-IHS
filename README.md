# Doom com Integração DE2I-150

Este projeto combina um motor de jogo estilo Doom, desenvolvido com SDL, com funcionalidades integradas à placa DE2I-150. Ele utiliza os recursos da placa para enriquecer a experiência do jogo, como exibição de informações no LCD, controle por botões e switches, e uso do display de 7 segmentos.

## Estrutura do Projeto

### Diretórios Principais

- **`driver/`**: Contém os drivers necessários para a comunicação com a placa DE2I-150. Inclui:
  - **`char/`**: Drivers para dispositivos de caractere.
  - **`pci/`**: Drivers para dispositivos PCI, incluindo o suporte à DE2I-150.
  
- **`docs/`**: Documentação relacionada à configuração e uso da placa DE2I-150.

- **`mapeamento/`**: Arquivos de mapeamento e configuração para a DE2I-150, incluindo projetos de hardware.

- **`src/`**: Código-fonte do motor de jogo Doom, com as seguintes funcionalidades:
  - **`core/`**: Lógica principal do jogo.
  - **`renderer/`**: Renderização gráfica.
  - **`wad/`**: Manipulação de arquivos WAD.
  - **`utils.c` e `logger.c`**: Utilitários e sistema de logs.

- **`exemples/`**: Exemplos de uso do driver e integração com a placa, em C e Python.

- **`resources/`**: Recursos adicionais, como o arquivo WAD do jogo.

## Funcionalidades Integradas com a DE2I-150

- **LCD**: Exibe informações como a vida e a armadura do jogador.
- **Botões**: Permitem trocar de arma durante o jogo.
- **Display de 7 segmentos**: Mostra a quantidade de munição da arma atual.
- **Switches**: O primeiro switch é usado para pausar o jogo.
- **LEDs verdes**: Os LEDs verdes acima dos botões acendem conforme a arma atualmente selecionada.

## Requisitos

- **Hardware**: Placa DE2I-150.
- **Software**: SDL2, compilador C e ferramentas de desenvolvimento para a DE2I-150.

## Como Compilar e Executar

1. **Compilar os drivers**:
   - Navegue até o diretório `driver/char` e `driver/pci` e execute `make` para compilar os drivers.

2. **Configurar a placa**:
   - Carregue os arquivos de mapeamento disponíveis em `mapeamento/` na DE2I-150.

3. **Compilar o jogo**:
   - Navegue até o diretório `src/` e execute `make` para compilar o motor de jogo.

4. **Executar o jogo**:
   - Carregue os drivers compilados e execute o binário gerado do jogo.


## Colaboradores

| [<img src="https://avatars.githubusercontent.com/u/129231720?v=4" width=115><br><sub>Henrique César Higino Holanda Cordeiro</sub>](https://github.com/SapoSopa) | [<img src="https://avatars.githubusercontent.com/u/123107373?v=4" width=115><br><sub>Márcio Campos Júnior</sub>](https://github.com/MAACJR032) | [<img src="https://avatars.githubusercontent.com/u/98539736?v=4" width=115><br><sub>João Victor</sub>](https://github.com/jambis-prg) | [<img src="https://avatars.githubusercontent.com/u/96800329?v=4" width=115><br><sub>Luiz Gustavo</sub>](https://github.com/Zed201) | [<img src="" width=115><br><sub>Wilton Alves Sales</sub>]() |
| :---: | :---: | :---: | :---: | :---: |