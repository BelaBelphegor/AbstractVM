/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:41:39 by tiboitel          #+#    #+#             */
/*   Updated: 2017/01/16 17:07:06 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_FACTORY_HPP
# define OPERAND_FACTORY_HPP
#include <string>
#include <map>
#include "IOperand.hpp"

class OperandFactory
{
	public:
		OperandFactory();
		OperandFactory(const OperandFactory&);
		const OperandFactory &operator=(const OperandFactory&);
		IOperand const *createOperand(eOperandType type, std::string const &value) const;
		~OperandFactory();
	private:
		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;
		std::map<eOperandType, IOperand const* (OperandFactory::*)(std::string const & value) const>	create;
};

#endif
