#ifndef __GENERATOR_BASETYPE_H
#define __GENERATOR_BASETYPE_H
#include <type_traits>
#include "IfThenElse.h"
//=====================================================================
namespace Generator{
//=====================================================================
struct EmptyRepository{};
//---------------------------------------------------------
/*! \brief Create sucht nach einer Spezialisierung von
 *  Component in dem Context
 * \tparam Context: der Context in dem die Komponente gesucht wird
 * \tparam ConfigurationRepository: enthaelt die Auspr�gungen der
 * Varianten des Systems
 * und bildet mit Context den Gesamtkontext
 * \tparam Origin: der urspruengliche Kontext, in dem der Basistyp einer
 * Komponente gesucht werden kann
 * \result type: der Implementierungstyp fuer die angeforderte Komponente
 *
 * \remark Anwendung: Create<LPC2148>::type, wobei LPC2148 ein Selector
 * sein muss f�r den
 * oder f�r einen Basistyp des Selectors
 * eine Component spezialisert sein muss.
 * \code
 *struct LPC2144 : ...
 *struct LPC2146 : Generator::SelectorBase<LPC2144>{};
 *struct LPC2148 : Generator::SelectorBase<LPC2146>{};
 *
 *template<class ConfigRep, Origin>
 *struct Component<LPC2144, ConfigRep, Origin>{
 *	typedef ... type;
 *};
 *
 * typedef Create<LPC2148>::type hal; // liefert den in Component definierten Typ
 * \endcode
 * \see SelectorBase
 */
template<   class Context, 
            class ConfigurationRepository = EmptyRepository,
            class Origin = Context
            >
struct Create;
//! CT<Context> ComponentType erzeugt den Typ, mit CT<Context> var; wird ein Objekt angelegt
template<	class Context,
			class ConfigurationRepository = EmptyRepository,
			class Origin = Context>
using CT = typename Create<Context, ConfigurationRepository, Origin>::type;
//---------------------------------------------------------
/*! Component, muss f�r einen Selector spezialisiert werden
 * \remark Spezialisierte Component definieren den Implmenetierungstyp
 * typedef ... type;
 * \see Create
 */

template<class Selector, class Origin, class ConfigurationRepository>
struct Component;
//---------------------------------------------------------
/*! \brief SimpleSelector, erzeugt aus zwei beliebigen Typen T1, T2
 * einen Context, base_type ist SelectorDefault
 */
template<class T1, class T2>
struct SS;
//---------------------------------------------------------
/*! \brief CompositeSelector, erzeugt aus einem beliebigen Typ T
 * und einem Selector einen Context
 */
template<typename T, typename Selector>
struct CS;
//---------------------------------------------------------
/*! \brief DoubleDispatch Selector, erzeugt aus zwei Selectoren
 * einen Context, der letzte Selector degeneriert als erstes
 */
template<class Selector1, class Selector2>
struct DD;
//---------------------------------------------------------
/*! \brief NumberOf Zur Auswahl einer von mehreren Componenten
 * NO<GPIO, 1>
 */
template<class ComponentType, unsigned int Number>
struct NO
{
	typedef ComponentType type;
	static const unsigned int value = Number;
//	enum { value = Number };
};
//---------------------------------------------------------
/*! \brief SelectorDefault zur Spezialisierung f�r Komponenten
 * die allgemein zur Verf�gung stehen
 * \remark Default f�r SelectorBase<...>
 */
struct SelectorDefault;
//---------------------------------------------------------
/*! \brief Default BaseTypeTemplate f�r SelectorBase
 * liefert CurrentContext::base_type
 */
template<class CurrentSelector>
struct BaseType{
	typedef typename CurrentSelector::base_type type;
};
/*! \brief SelectorBase
    Jeder Selector der Create als Context �bergeben wird, 
    muss von SelectorBase erben oder die Schnittstelle
    BaseType<CurrentSelector>::type und base_type zur Verf�gung stellen.

    SelectorBase wird f�r Typ Hierarchien (Selectoren) ben�tigt
    die die Metainformationen �ber ihre Basisklassen 
    zur Verf�gung stellen m�ssen. Damit lassen
    sich Component (templates) f�r die jeweilige 
    Hierarchie Stufe definieren, die an die spezielleren Typen
    vererbt werden
    diese werden vom Compiler ausgew�hlt 
*/
template <typename BASETYPE=SelectorDefault,
		 template<class> class CalculateBaseType=BaseType>
struct SelectorBase
{
    typedef BASETYPE base_type;

    /*!BaseType berechnet den n�chsten Typ
     * mit dem ein Context erzeugt wird
     * f�r den eine Componente gesucht wird
     */
    template<class CurrentSelector>
    struct BaseType : CalculateBaseType<CurrentSelector>{};

    static char const * name(){ return "Generator::SelectorBase"; }
};
//==============================================================
/*! replaceBaseType
 * Anwendung: struct Context : replaceBaseType<RadioLuxus, RadioSimple, Mock::Base>{}
 * Create<Context>::type liefert als Basisklasse anstatt RadioSimple Mock::Base.
 * Egal wie lange die Typhierarchie ist, Mock::Base wird vor RadioSimple eingef�gt.
 * z.B. RadioLuxus -> RadioAdvanced -> RadioSimple wird zu
 *  RadioLuxus -> RadioAdvanced -> Mock::Base -> RadioSimple
 *  wenn Mock::Base -> RadioSimple als BaseType definiert
 */
template<class Context, class toBeReplaced, class replacement>
struct replaceBaseType //TypeFunctor
{
	typedef Context base_type;

	// MemberTypeFunction
	template<class CurrentSelector>
	struct BaseType{
		typedef typename
		IF<
			std::is_same<
				typename Context::template BaseType<CurrentSelector>::type,
				toBeReplaced
						>::value,

			replacement,
			typename Context::template BaseType<CurrentSelector>::type>
		::type type;
	};
};

//==============================================================
/*! Experimentel
 * Klasse mit Default BaseTypeSelector f�r SelectorBase
 * liefert CurrentContext::base_type
 */
struct BaseTypeSelector{
	template<class CurrentContext>
	struct BaseType{
		typedef typename CurrentContext::base_type type;
	};
};
//!Experimentel
template <typename BASETYPE=SelectorDefault,
		 typename BaseTypeTemplate=BaseTypeSelector>
struct SelectorBaseNeu
{
    typedef BASETYPE base_type;

    //BaseType berechnet den n�chsten Typ
    // mit dem ein Context erzeugt wird
    // f�r den eine Componente gesucht wird
    template<class CurrentContext>
    struct BaseType : BaseTypeTemplate::template BaseType<CurrentContext>{};

    static char const * name(){ return "Generator::SelectorBaseNeu"; }
};
//==============================================================
/*!
 * Muss f�r Typen spezialisiert werden, die keine
 * static char const* name() Operation zur Verf�gung stellen
 * und f�r die Dokumentation generiert werden soll
 */
template<class T>
struct name{
	template<class OStream>
	static void print(OStream& os){
		os << T::name();
	}
};
//---------------------------------------------------------
//! nur f�r den Generator
struct SelectorEnd //: SelectorBase<SelectorNext>
{
	static const char* name(){ return "Generator::SelectorEnd";}
};
/*! \brief SelectorDefault zur Spezialisierung f�r Komponenten
 * die allgemein zur Verf�gung stehen
 * \remark Default f�r SelectorBase<...>
 */
struct SelectorDefault : SelectorBase<SelectorEnd>{
	static const char* name(){ return "Generator::SelectorDefault";}
};
} // namespace Generator

#endif //__GENERATOR_BASETYPE_H

