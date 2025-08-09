Qué es una FSM (Finite State Machine)
Una FSM o Máquina de Estados Finita es donde un objeto solo puede estar en un estado a la vez (por ejemplo: IDLE, JUMPING, ATTACKING) y solo puede cambiar a otro estado siguiendo reglas de transición definidas.
En un videojuego, esto sirve para controlar el flujo de acciones y evitar que el personaje haga cosas no deseadas, como disparar mientras está en el aire si el diseño lo prohíbe.

Por qué usar un enum en lugar de múltiples bool

Claridad: Con un enum como State::IDLE queda claro que el personaje solo está en un estado a la vez, mientras que con múltiples bool podrías tener combinaciones incoherentes (isJumping = true y isAttacking = true al mismo tiempo).

Mantenimiento: Si agregas un nuevo estado, solo lo añades al enum y al switch, no tienes que crear más variables bool y revisar todos los if.

Menos errores: Evita estados contradictorios que podrían romper la lógica del juego.
Código más limpio: La lógica de transición se maneja en un solo bloque switch en vez de estar dispersa en múltiples condiciones booleanas.

Diferencia de responsabilidad entre Personaje::handleInput y InputHandler
InputHandler (Patrón Command)
Su única responsabilidad es mapear entradas de usuario a acciones.
No sabe nada sobre las reglas del juego ni sobre si la acción es válida en ese momento.
Ejemplo: Si el jugador presiona 'w', InputHandler devuelve el comando SaltarCommand.
InputHandler traduce teclas → comandos (qué quiere hacer el jugador).

Personaje::handleInput (FSM)
Su responsabilidad es decidir si la acción se puede realizar según el estado actual.
Implementa las reglas de transición: qué pasa si el personaje está en el aire, atacando, o quieto.
Ejemplo: Si recibe 'w' pero está en JUMPING, ignorará el salto y mostrará un mensaje.
Personaje::handleInput valida y controla si esa acción es posible (qué puede hacer el personaje en este momento).

IDLE --> JUMPING : input 'w'
IDLE --> ATTACKING : input 'f'

JUMPING --> IDLE : después de update
JUMPING --> JUMPING : ignora input

ATTACKING --> IDLE : después de update
ATTACKING --> ATTACKING : ignora input