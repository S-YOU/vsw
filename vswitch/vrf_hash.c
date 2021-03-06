/*
 * Copyright 2017 Nippon Telegraph and Telephone Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdint.h>
#include <rte_jhash.h>

/*
 * Hash function for VRF RD
 *
 * This hash function shall be used through out lagopus to share the
 * pre-calculated hash key.
 */ 
uint32_t
lagopus_vrf_hash_func(const void *key, uint32_t length, uint32_t initval)
{
	const uint32_t *k = key;
	return rte_jhash_2words(k[0], k[1], initval);
}
