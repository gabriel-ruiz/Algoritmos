(define create-tree
	(lambda (lista arbol)
		(let tree ((lista lista) (arbol arbol))
			(cond 
				((null? lista)
					arbol
				)
				(else
					(create-tree (cdr lista) (add-node (car lista) arbol))
				)
			)
		)
	)
)
