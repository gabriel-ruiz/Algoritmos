(define get 
	(lambda (elem arbol)
		(let aux ((elem elem) (arbol arbol))
			(if (null? arbol)
				#f
				(cond
					((eqv? arbol #f)
						#f
					)
					((= elem (car arbol))
						arbol
					)
					((< elem (car arbol))
						(get elem (car (cdr arbol)))
					)
					((> elem (car arbol))
						(get elem (car (cddr arbol)))
					)
				)
			)
		)
	)
)
