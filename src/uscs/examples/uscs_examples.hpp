/** @file

 Declaration of interfaces for a USCS example, as well as functions to sample
 USCS examples with prescribed parameters (according to some distribution).

 *****************************************************************************
 * @author     This file is part of libsnark, developed by SCIPR Lab
 *             and contributors (see AUTHORS).
 * @copyright  MIT license (see LICENSE file)
 *****************************************************************************/

#ifndef USCS_EXAMPLES_HPP_
#define USCS_EXAMPLES_HPP_

#include "uscs/uscs.hpp"

namespace libsnark {

/**
 * A USCS example comprises a USCS constraint system, USCS input, and USCS witness.
 */
template<typename FieldT>
struct uscs_example {
    uscs_constraint_system<FieldT> constraint_system;
    uscs_variable_assignment<FieldT> input;
    uscs_variable_assignment<FieldT> witness;

    uscs_example<FieldT>() = default;
    uscs_example<FieldT>(const uscs_example<FieldT> &other) = default;
    uscs_example<FieldT>(const uscs_constraint_system<FieldT> &constraint_system,
                         const uscs_variable_assignment<FieldT> &input,
                         const uscs_variable_assignment<FieldT> &witness) :
        constraint_system(constraint_system),
        input(input),
        witness(witness)
    {};
    uscs_example<FieldT>(uscs_constraint_system<FieldT> &&constraint_system,
                         uscs_variable_assignment<FieldT> &&input,
                         uscs_variable_assignment<FieldT> &&witness) :
        constraint_system(std::move(constraint_system)),
        input(std::move(input)),
        witness(std::move(witness))
    {};
};

/**
 * Generate an USCS example such that:
 * - the number of constraints of the USCS constraint system is num_constraints;
 * - the number of variables of the USCS constraint system is (approximately) num_constraints;
 * - the number of inputs of the USCS constraint system is num_inputs;
 * - the USCS input consists of ``full'' field elements (typically require the whole log|Field| bits to represent).
 */
template<typename FieldT>
uscs_example<FieldT> generate_uscs_example_with_field_input(const size_t num_constraints,
                                                            const size_t num_inputs);

/**
 * Generate an USCS example such that:
 * - the number of constraints of the USCS constraint system is num_constraints;
 * - the number of variables of the USCS constraint system is (approximately) num_constraints;
 * - the number of inputs of the USCS constraint system is num_inputs;
 * - the USCS input consists of binary values (as opposed to ``full'' field elements).
 */
template<typename FieldT>
uscs_example<FieldT> generate_uscs_example_with_binary_input(const size_t num_constraints,
                                                             const size_t num_inputs);

} // libsnark

#include "uscs/examples/uscs_examples.tcc"

#endif // USCS_EXAMPLES_HPP_
