/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:41:39 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/24 18:36:47 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_BIND_H
# define KEY_BIND_H

# include "window.h"
# include "fdf.h"

# define ESC_KEY 65307
# define P_KEY 112

enum e_keyboard
{
	UP_ARROW = 65362,
	DOWN_ARROW = 65364,
	LEFT_ARROW = 65361,
	RIGHT_ARROW = 65363,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100,
	I_KEY = 105,
	PLUS_KEY = 65451,
	MINUS_KEY = 65453,
	NUM_6 = 65432,
	NUM_4 = 65430,
	NUM_7 = 65429,
	NUM_9 = 65434,
	NUM_8 = 65431,
	NUM_2 = 65433,
};

typedef void	(*t_key_func)(t_topo *c_map);

typedef struct s_key
{
	enum e_keyboard		key;
	t_key_func			func;
}	t_key;

#endif
