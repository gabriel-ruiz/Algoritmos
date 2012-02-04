(define pre-order
	(lambda (arbol)
		(if(null? arbol)
			arbol
			(cond
				((eqv? arbol #f)
					'()
				)
				(else
					(cons (car arbol) (append (pre-order (car (cdr arbol))) (pre-order (car (cddr arbol)))))
				)
			)
		)
	)
)
