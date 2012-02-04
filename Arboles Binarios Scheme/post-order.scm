(define post-order
	(lambda (arbol)
		(if(null? arbol)
			arbol
			(cond
				((eqv? arbol #f)
					'()
				)
				(else
					(append (append (post-order (car (cdr arbol))) (post-order (car (cddr arbol)))) (list (car arbol)))
				)
			)
		)
	)
)
