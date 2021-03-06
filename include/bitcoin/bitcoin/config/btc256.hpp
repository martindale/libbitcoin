/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * libbitcoin is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_CONFIG_BTC256_HPP
#define LIBBITCOIN_CONFIG_BTC256_HPP

#include <iostream>
#include <bitcoin/bitcoin/define.hpp>
#include <bitcoin/bitcoin/formats/base16.hpp>

namespace libbitcoin {
namespace config {

/**
 * Serialization helper for a bitcoin 256 bit hash.
 */
class BC_API btc256
{
public:
    /**
     * A list of bitcoin 256 bit hashes.
     * This must provide operator<< for ostream in order to be used as a 
     * boost::program_options default_value.
     */
    typedef std::vector<btc256> list;

    /**
     * Default constructor.
     */
    btc256();

    /**
     * Copy constructor.
     * @param[in]  other  The object to copy into self on construct.
     */
    btc256(const btc256& other);

    /**
     * Initialization constructor.
     * @param[in]  hexcode  The hash value in string hexidecimal form.
     */
    btc256(const std::string& hexcode);

    /**
     * Initialization constructor.
     * @param[in]  value  The hash value to initialize with.
     */
    btc256(const hash_digest& value);
    
    /**
     * Get the hash as a string.
     * @return The hash in the string hexidecimal form.
     */
    std::string to_string() const;

    /**
     * Override the equality operator.
     * @param[in]  other  The other object with which to compare.
     */
    bool operator==(const btc256& other) const;

    /**
     * Cast to internal type.
     * @return  This object's value cast to internal type.
     */
    operator const hash_digest&() const;

    /**
     * Define stream in. Throws if input is invalid.
     * @param[in]   input     The input stream to read the value from.
     * @param[out]  argument  The object to receive the read value.
     * @return                The input stream reference.
     */
    friend std::istream& operator>>(std::istream& input,
        btc256& argument);

    /**
     * Define stream out.
     * @param[in]   output    The output stream to write the value to.
     * @param[out]  argument  The object from which to obtain the value.
     * @return                The output stream reference.
     */
    friend std::ostream& operator<<(std::ostream& output,
        const btc256& argument);

private:
    hash_digest value_;
};

} // namespace config
} // namespace libbitcoin

#endif
