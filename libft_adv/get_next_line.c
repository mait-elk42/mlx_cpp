/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:13:31 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/20 14:07:21 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkosf(int fd)
{
	return (fd < 0 || BUFFER_SIZE <= 0
		|| read(fd, 0, 0) < 0 || BUFFER_SIZE > 2147483647);
}

static char	*freeosf(char *result, char **s_bfr, char *r_bfr, int fd)
{
	return (free(result), free(s_bfr[fd]), free(r_bfr), s_bfr[fd] = 0, NULL);
}

static char	*freeosf2(char **s_bfr, int fd)
{
	if (fd < 0 || fd > OPEN_MAX)
		return (0);
	if (s_bfr[fd])
		free(s_bfr[fd]);
	s_bfr[fd] = 0;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*s_bfr[OPEN_MAX];
	char		*r_bfr;
	char		*result;
	int			read_len;

	read_len = 1;
	result = 0;
	if (checkosf(fd))
		return (freeosf2(s_bfr, fd));
	result = _nsx_join(result, s_bfr[fd]);
	s_bfr[fd] = (free(s_bfr[fd]), NULL);
	r_bfr = malloc((size_t)BUFFER_SIZE + 1);
	if (!r_bfr)
		return (free(result), free(s_bfr[fd]), s_bfr[fd] = NULL, NULL);
	while (_nsx_there_nwline(result) != 1 && read_len)
	{
		read_len = read(fd, r_bfr, BUFFER_SIZE);
		if (read_len == -1)
			return (freeosf(result, s_bfr, r_bfr, fd));
		r_bfr[read_len] = '\0';
		result = _nsx_join(result, r_bfr);
		if (!result)
			break ;
	}
	return (free(r_bfr), _nsx_trimnl(result, &s_bfr[fd]));
}
