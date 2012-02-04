(define delete-node
	(lambda (elem arbol)
		(let temp ((elem elem) (arbol arbol) (left (car (cdr arbol))) (right (car (cddr arbol))))
			(if (null? arbol)
				arbol
				(if (not (is-in elem arbol))
					arbol				
					(if (eqv? elem (car arbol))				
						(cond
						;caso en ke car arbol es igual a elem
							;caso en ke ambos hijos son #f
							((and (eqv? left #f) (eqv? right #f))
								'()						
							)
							;caso en ke solo hijo izquierdo es #f
							((and (eqv? left #f) (not (eqv? right #f)))
								right
							)	
							;caso en ke solo hijo derecho es #f
							((and (not (eqv? left #f)) (eqv? right #f))
								left
							)
							;caso en ke ningun hijo es #f. 
							((and (not (eqv? left #f)) (not (eqv? right #f)))
								(if (eqv? (delete-node (car (minimum right)) right) '()) 
									(list (car (minimum right)) left #f)								
									(list (car (minimum right)) left (delete-node (car (minimum right)) right))
								) 
								
							)
						)
						;si el car del arbol no es igual a elem
						(cond 
							((< elem (car arbol))
								(if (null? (delete-node elem left))
									(list (car arbol) #f right)
									(list (car arbol) (delete-node elem left) right)
								)
							)
							((> elem (car arbol))
								(if (null? (delete-node elem right))
									(list (car arbol) left #f)
									(list (car arbol) left (delete-node elem right))
								)
								
							)
						)
					)
				)
			)
		)
	)
)
