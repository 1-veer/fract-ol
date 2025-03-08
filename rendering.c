/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:00:55 by abougati          #+#    #+#             */
/*   Updated: 2025/03/08 17:09:54 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fract_ol.h"

void   pixel_handler(int x, int y, t_fract *fract)
{
    
}

 void rendering (t_fract *fract)
{
    int y;
    int x;
    
    y = 0;
    while (y++ < 1000)
        {
            x = 0;
            while (x++ < 1000)
                pixel_handler(x, y, fract);
        }    
    
}