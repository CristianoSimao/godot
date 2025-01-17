/*************************************************************************/
/*  gltf_template_convert.h                                              */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef GLTF_TEMPLATE_CONVERT_H
#define GLTF_TEMPLATE_CONVERT_H

#include "core/templates/hash_set.h"
#include "core/variant/array.h"
#include "core/variant/dictionary.h"

namespace GLTFTemplateConvert {
template <class T>
static Array to_array(const Vector<T> &p_inp) {
	Array ret;
	for (int i = 0; i < p_inp.size(); i++) {
		ret.push_back(p_inp[i]);
	}
	return ret;
}

template <class T>
static Array to_array(const HashSet<T> &p_inp) {
	Array ret;
	typename HashSet<T>::Iterator elem = p_inp.begin();
	while (elem) {
		ret.push_back(*elem);
		++elem;
	}
	return ret;
}

template <class T>
static void set_from_array(Vector<T> &r_out, const Array &p_inp) {
	r_out.clear();
	for (int i = 0; i < p_inp.size(); i++) {
		r_out.push_back(p_inp[i]);
	}
}

template <class T>
static void set_from_array(HashSet<T> &r_out, const Array &p_inp) {
	r_out.clear();
	for (int i = 0; i < p_inp.size(); i++) {
		r_out.insert(p_inp[i]);
	}
}

template <class K, class V>
static Dictionary to_dict(const HashMap<K, V> &p_inp) {
	Dictionary ret;
	for (const KeyValue<K, V> &E : p_inp) {
		ret[E.key] = E.value;
	}
	return ret;
}

template <class K, class V>
static void set_from_dict(HashMap<K, V> &r_out, const Dictionary &p_inp) {
	r_out.clear();
	Array keys = p_inp.keys();
	for (int i = 0; i < keys.size(); i++) {
		r_out[keys[i]] = p_inp[keys[i]];
	}
}
} //namespace GLTFTemplateConvert

#endif // GLTF_TEMPLATE_CONVERT_H
