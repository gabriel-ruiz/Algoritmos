(define is-in 
	(lambda (elem arbol)
		(let func ((elem elem) (arbol arbol))
			(if (null? arbol)
				#f
				(cond 
					((eqv? arbol #f)
						#f
					)
					((= elem (car arbol))
						#t
					)
					((< elem (car arbol))
						(is-in elem (car (cdr arbol)))
					)
					((> elem (car arbol))
						(is-in elem (car (cddr arbol)))
					)
				)
			)
		)
	)
)
